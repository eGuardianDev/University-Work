#ifndef ALGORITHMS_HPP__
#define ALGORITHMS_HPP__

#include <cstdint>
#include <cmath>
#include <vector>

void Algo_Invert_Colours(uint8_t* src, uint8_t* dst, int size)
{
    for(int i =0;i <size;++i){
        long long base = i*3;
        if(base+2 <= size){
            dst[base+2] = 255 - src[base +2];
            dst[base+1] = 255 - src[base +1];
            dst[base+0] = 255 - src[base +0];
        }
    }
}
void Algo_Gray_Scale(uint8_t* src, uint8_t* dst, int size)
{
    for(int i =0;i <size;++i){
        long long base = i*3;
        if(base+2 <= size){
            uint8_t gray = 0.299 * src[base+2] + 0.587 * src[base+1]  + 0.114 * src[base+0];
            dst[base+2] = gray;
            dst[base+1] = gray;
            dst[base+0] = gray;
        }
    }
}
void Algo_Black_White(uint8_t* src, uint8_t* dst, int size)
{
    for(int i =0;i <size;++i){
        long long base = i*3;
        if(base+2 <= size){
            uint8_t value = 0.299 * src[base+2] + 0.587 * src[base+1]  + 0.114 * src[base+0];
            if(value >= 127) value = 255;
            else value = 0; 
            dst[base+2] = value;
            dst[base+1] = value;
            dst[base+0] = value;
        }
    }
}
void Algo_Sobel_Edge(uint8_t* src, uint8_t* dst, int width, int height)
{
    int stride = ((width * 3 + 3) & ~3);  
    int sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int sobelY[3][3] = {
        { 1,  2,  1},
        { 0,  0,  0},
        {-1, -2, -1}
    };

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {

            int GxB = 0, GyB = 0;
            int GxG = 0, GyG = 0;
            int GxR = 0, GyR = 0;

            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {

                    int px = x + kx;
                    int py = y + ky;
                    int idx = py * stride + px * 3;

                    int b = src[idx + 0];
                    int g = src[idx + 1];
                    int r = src[idx + 2];

                    int kxv = sobelX[ky + 1][kx + 1];
                    int kyv = sobelY[ky + 1][kx + 1];

                    GxB += b * kxv;  GyB += b * kyv;
                    GxG += g * kxv;  GyG += g * kyv;
                    GxR += r * kxv;  GyR += r * kyv;
                }
            }

            int magB = std::min(255, (int)std::sqrt(GxB*GxB + GyB*GyB));
            int magG = std::min(255, (int)std::sqrt(GxG*GxG + GyG*GyG));
            int magR = std::min(255, (int)std::sqrt(GxR*GxR + GyR*GyR));

            int out = y * stride + x * 3;
            dst[out + 0] = magB;
            dst[out + 1] = magG;
            dst[out + 2] = magR;
        }
    }
}


void gaussian_blur(
    const uint8_t* src,
    uint8_t* dst,
    int width,
    int height,
    int stride,
    int radius,
    const float* kernel,
    int y_start,
    int y_end
) {
    for (int y = y_start; y < y_end; y++) {
        for (int x = radius; x < width - radius; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {

                    int idx = (y + ky) * stride + (x + kx) * 3;
                    float w = kernel[(ky + radius) * (2*radius + 1) + (kx + radius)];

                    sumB += src[idx + 0] * w;
                    sumG += src[idx + 1] * w;
                    sumR += src[idx + 2] * w;
                }
            }

            int outIdx = y * stride + x * 3;
            dst[outIdx + 0] = (uint8_t)std::clamp(sumB, 0.0f, 255.0f);
            dst[outIdx + 1] = (uint8_t)std::clamp(sumG, 0.0f, 255.0f);
            dst[outIdx + 2] = (uint8_t)std::clamp(sumR, 0.0f, 255.0f);
        }
    }
}
void Algo_Gaussian_Blur(uint8_t* src, uint8_t* dst, int width, int height, unsigned int threads = 0)
{
    int stride = ((width * 3 + 3) & ~3);  
    const int radius = 7;
    const int ksize = radius * 2 + 1;
    const float sigma = 3.0f;

    // Copy borders
    memcpy(dst, src, stride * height);

    // Build kernel
    std::vector<float> kernel(ksize * ksize);
    float sum = 0.0f;

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            float v = std::exp(-(x*x + y*y) / (2 * sigma * sigma));
            kernel[(y + radius) * ksize + (x + radius)] = v;
            sum += v;
        }
    }

    for (float& v : kernel)
        v /= sum;

    // Thread setup
    if(threads == 0){
        threads = std::thread::hardware_concurrency();
        if(threads == 0) threads = 4;
    } 
    int rows = height - 2 * radius;
    int rows_per_thread = rows / threads;

    std::vector<std::thread> pool;
    int y = radius;

    std::cout << "Starting gaussian blur with threads: " << threads << std::endl;
    for (unsigned i = 0; i < threads; i++) {
        int y_end = (i == threads - 1)
                    ? height - radius
                    : y + rows_per_thread;

        pool.emplace_back(
            gaussian_blur,
            src, dst,
            width, height, stride,
            radius,
            kernel.data(),
            y, y_end
        );

        y = y_end;
    }

    for (auto& t : pool)
        t.join();
}

static void gabor_filter(
    const uint8_t* src,
    uint8_t* dst,
    int width,
    int height,
    int stride,
    int radius,
    int ksize,
    const float* kernel,
    int y_start,
    int y_end
) {
    const float BRIGHTNESS = 2.0f;

    for (int y = y_start; y < y_end; y++) {
        for (int x = radius; x < width - radius; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {

                    int idx =
                        (y + ky) * stride +
                        (x + kx) * 3;

                    float w =
                        kernel[(ky + radius) * ksize + (kx + radius)];

                    sumB += src[idx + 0] * w;
                    sumG += src[idx + 1] * w;
                    sumR += src[idx + 2] * w;
                }
            }

            sumB = std::abs(sumB) * BRIGHTNESS;
            sumG = std::abs(sumG) * BRIGHTNESS;
            sumR = std::abs(sumR) * BRIGHTNESS;

            int outIdx = y * stride + x * 3;
            dst[outIdx + 0] =
                (uint8_t)std::clamp(sumB, 0.0f, 255.0f);
            dst[outIdx + 1] =
                (uint8_t)std::clamp(sumG, 0.0f, 255.0f);
            dst[outIdx + 2] =
                (uint8_t)std::clamp(sumR, 0.0f, 255.0f);
        }
    }
}

void Algo_Gabor_Filter(
    const uint8_t* src,
    uint8_t* dst,
    int width,
    int height,
    int ksize,
    float sigma,
    float theta,
    float lambda,
    float gamma,
    float psi,
    unsigned int threads = 0
) {
    int stride = ((width * 3 + 3) & ~3);
    int radius = ksize / 2;

    memcpy(dst, src, stride * height);

    std::vector<float> kernel(ksize * ksize);
    float sum = 0.0f;

    float cos_t = std::cos(theta);
    float sin_t = std::sin(theta);

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {

            float xr =  x * cos_t + y * sin_t;
            float yr = -x * sin_t + y * cos_t;

            float g =
                std::exp(-(xr * xr + gamma * gamma * yr * yr) /
                         (2.0f * sigma * sigma));

            float w =
                std::cos(2.0f * M_PI * xr / lambda + psi);

            float v = g * w;
            kernel[(y + radius) * ksize + (x + radius)] = v;
            sum += std::abs(v);
        }
    }

    for (float& v : kernel)
        v /= sum;

    if (threads == 0){
        threads = std::thread::hardware_concurrency();
        if(threads == 0) threads = 4;
    } 

    int y_begin = radius;
    int y_end   = height - radius;
    int rows    = y_end - y_begin;
    int rows_per_thread = rows / threads;

    std::vector<std::thread> pool;
    int y = y_begin;

    for (unsigned i = 0; i < threads; i++) {
        int y_stop = (i == threads - 1)
                   ? y_end
                   : y + rows_per_thread;

        pool.emplace_back(
            gabor_filter,
            src, dst,
            width, height, stride,
            radius, ksize,
            kernel.data(),
            y, y_stop
        );

        y = y_stop;
    }

    for (auto& t : pool)
        t.join();
}
#endif // ALGORITHMS_HPP__