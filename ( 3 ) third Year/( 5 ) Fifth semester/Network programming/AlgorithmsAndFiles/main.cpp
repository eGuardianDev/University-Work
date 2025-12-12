
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstdint>

#include "BMP_File.hpp"
#include "BMP_Manipulation.hpp"
#include "Algorithms.hpp"
#include <cmath>
#include <vector>
#include <chrono>
#include <algorithm>
#include <thread>
int fd;

///
std::vector<float> makeGaborKernel(int ksize, float sigma, float theta, float lambda, float gamma, float psi)
{
    int radius = ksize / 2;
    std::vector<float> kernel(ksize * ksize);

    float sum = 0.0f;  
    float cos_t = std::cos(theta);
    float sin_t = std::sin(theta);

    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {

            float xr =  x * cos_t + y * sin_t;
            float yr = -x * sin_t + y * cos_t;

            float g = std::exp(-(xr*xr + gamma*gamma * yr*yr) / (2 * sigma*sigma));
            float w = std::cos(2 * M_PI * xr / lambda + psi);

            float value = g * w;

            kernel[(y + radius) * ksize + (x + radius)] = value;
            sum += std::abs(value);
        }
    }

    // normalize
    for (float &v : kernel) v /= sum;

    return kernel;
}
void applyGaborFilter(uint8_t *src, uint8_t *dst, int width, int height, 
                      const std::vector<float> &kernel, int ksize)
{
    int radius = ksize / 2;
    const float BRIGHTNESS = 2.0f; 

    for (int y = radius; y < height - radius; y++) {
        for (int x = radius; x < width - radius; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {

                    int px = x + kx;
                    int py = y + ky;

                    int idx = (py * width + px) * 3;

                    float w = kernel[(ky + radius) * ksize + (kx + radius)];

                    sumB += src[idx + 0] * w;
                    sumG += src[idx + 1] * w;
                    sumR += src[idx + 2] * w;

                }
            }

            sumB = std::abs(sumB) * BRIGHTNESS;
            sumG = std::abs(sumG) * BRIGHTNESS;
            sumR = std::abs(sumR) * BRIGHTNESS;

            int outIdx = (y * width + x) * 3;
            dst[outIdx + 0] = std::clamp((int)std::abs(sumB), 0, 255);
            dst[outIdx + 1] = std::clamp((int)std::abs(sumG), 0, 255);
            dst[outIdx + 2] = std::clamp((int)std::abs(sumR), 0, 255);
        }
    }
}

void applyGaborFilterSection(uint8_t *src, uint8_t *dst,
                             int width, int height,
                             const std::vector<float> &kernel,
                             int ksize,
                             int yStart, int yEnd)
{
    int radius = ksize / 2;
    const float BRIGHTNESS = 2.0f;

    for (int y = yStart; y < yEnd; y++) {
        for (int x = radius; x < width - radius; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {

                    int px = x + kx;
                    int py = y + ky;
                    int idx = (py * width + px) * 3;

                    float w = kernel[(ky + radius) * ksize + (kx + radius)];

                    sumB += src[idx + 0] * w;
                    sumG += src[idx + 1] * w;
                    sumR += src[idx + 2] * w;
                }
            }

            sumB = std::abs(sumB) * BRIGHTNESS;
            sumG = std::abs(sumG) * BRIGHTNESS;
            sumR = std::abs(sumR) * BRIGHTNESS;

            int outIdx = (y * width + x) * 3;
            dst[outIdx + 0] = std::clamp((int)sumB, 0, 255);
            dst[outIdx + 1] = std::clamp((int)sumG, 0, 255);
            dst[outIdx + 2] = std::clamp((int)sumR, 0, 255);
        }
    }
}


///


inline uint8_t getPixel(uint8_t* data, int x, int y, int width, int channel)
{
    return data[(y * width + x) * 3 + channel];
}
std::vector<float> makeGaussianKernel15(float sigma = 3.0f)
{
    const int radius = 7;     // 15 = 2*7 + 1
    const int size = 15;
    std::vector<float> kernel(size);

    float sum = 0.0f;

    for (int i = -radius; i <= radius; i++) {
        float value = std::exp(-(i*i) / (2 * sigma * sigma));
        kernel[i + radius] = value;
        sum += value;
    }

    // Normalize
    for (int i = 0; i < size; i++)
        kernel[i] /= sum;

    return kernel;
}
void gaussianBlur15Horizontal(uint8_t* src, uint8_t* dst, int width, int height, const std::vector<float>& kernel)
{
    const int radius = 7;

    for (int y = 0; y < height; y++) {
        for (int x = radius; x < width - radius; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int k = -radius; k <= radius; k++) {
                int px = x + k;
                int idx = (y * width + px) * 3;

                sumB += src[idx + 0] * kernel[k + radius];
                sumG += src[idx + 1] * kernel[k + radius];
                sumR += src[idx + 2] * kernel[k + radius];
            }

            int out = (y * width + x) * 3;
            dst[out + 0] = (uint8_t)sumB;
            dst[out + 1] = (uint8_t)sumG;
            dst[out + 2] = (uint8_t)sumR;
        }
    }
}
void gaussianBlur15Vertical(uint8_t* src, uint8_t* dst, int width, int height, const std::vector<float>& kernel)
{
    const int radius = 7;

    for (int y = radius; y < height - radius; y++) {
        for (int x = 0; x < width; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int k = -radius; k <= radius; k++) {
                int py = y + k;
                int idx = (py * width + x) * 3;

                sumB += src[idx + 0] * kernel[k + radius];
                sumG += src[idx + 1] * kernel[k + radius];
                sumR += src[idx + 2] * kernel[k + radius];
            }

            int out = (y * width + x) * 3;
            dst[out + 0] = (uint8_t)sumB;
            dst[out + 1] = (uint8_t)sumG;
            dst[out + 2] = (uint8_t)sumR;
        }
    }
}
void gaussianBlur15x15_SLOW(uint8_t* src, uint8_t* dst, int width, int height)
{
    const int radius = 7;

    // Compute full 15×15 kernel at runtime (slow step #1)
    float kernel[15][15];
    float sum = 0;
    float sigma = 3.0f;

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            float value = std::exp(-(x*x + y*y) / (2 * sigma * sigma));
            kernel[y + radius][x + radius] = value;
            sum += value;
        }
    }

    // Normalize (slow step #2)
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            kernel[i][j] /= sum;

    // Apply convolution (slow step #3)
    for (int y = radius; y < height - radius; y++) {
        for (int x = radius; x < width - radius; x++) {

            float sumB = 0, sumG = 0, sumR = 0;

            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {

                    int px = x + kx;
                    int py = y + ky;

                    int idx = (py * width + px) * 3;

                    float w = kernel[ky + radius][kx + radius];

                    sumB += src[idx + 0] * w;
                    sumG += src[idx + 1] * w;
                    sumR += src[idx + 2] * w;
                }
            }

            int outIdx = (y * width + x) * 3;
            dst[outIdx + 0] = (uint8_t)sumB;
            dst[outIdx + 1] = (uint8_t)sumG;
            dst[outIdx + 2] = (uint8_t)sumR;
        }
    }
}

int computePixelSobel(uint8_t *buff, int x, int width)
{
    int sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int sobelY[3][3] = {
      {1,  2,  1},
      {0,  0,  0},
      {-1, -2, -1},
    };

    int Gx = 0;
    int Gy = 0;

    // Loop over the 3×3 block
    for (int ky = -1; ky <= 1; ky++) {
        for (int kx = -1; kx <= 1; kx++) {
            int pixel = buff[x + ky* width + kx*3];

            Gx += pixel * sobelX[ky + 1][kx + 1];
            Gy += pixel * sobelY[ky + 1][kx + 1];
        }
    }

    // Compute magnitude
    int magnitude = std::sqrt(Gx * Gx + Gy * Gy);

    // Clamp to 0–255
    if (magnitude > 255) magnitude = 255;

    return magnitude;
}

int computePixelLaplacian(uint8_t *buff, int x, int width)
{
    int small[3][3] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    }; 
    int big[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };


    int Gx = 0;
    int Gy = 0;

    // Loop over the 3×3 block
    for (int ky = -1; ky <= 1; ky++) {
        for (int kx = -1; kx <= 1; kx++) {
            int pixel = buff[x + ky* width + kx*3];

            Gx += pixel * small[ky + 1][kx + 1];
        }
    }

    // Compute magnitude
    int magnitude = std::sqrt(Gx * Gx + Gy * Gy);

    // Clamp to 0–255
    if (magnitude > 255) magnitude = 255;

    return magnitude;
}

void error(const char * msg){
    if(fd >=0){
        close(fd);
    }
    throw std::runtime_error(msg);
}

#define INPUT_FILE "compress/output.bmp"
#define OUTPUT_FILE "output.bmp"
#define MAX_FILE_SIZE 25 * 1024 * 1024  // 25 MB - 4K image, 24 bit


int main(int argc, char*argv[]){
    
        // * == open file == *
    fd = open(INPUT_FILE, O_RDONLY);

    if(fd < 0){
        error("File failed to open.");
    }

        // * == read file == *
    unsigned char buff_header[138];

    int size = read(fd, buff_header,138);

    bmp_header header = load_header(buff_header);  


    
    // * == verification == *
    uint16_t expected_signature = 'B' | 'M' << 8;
    if(header.signature != expected_signature){
        error("Opened file isn't a BMP format.");
    }

    header_print_basic(header);

    // * Reading data from image

    
    std::cout << "Data starts at " << header.data_offset << std::endl;
    
    lseek(fd,header.data_offset,SEEK_SET);
    
    uint8_t *buff_data = new uint8_t[MAX_FILE_SIZE];
    
    int size_of_read_data = read(fd, buff_data, MAX_FILE_SIZE);
    

    std::cout << "Size of data:  "<< size_of_read_data << std::endl;
    std::cout << "Size of image: "<< header.image_size << std::endl;
    std::cout << "Data is correctly loaded: " << std::boolalpha <<
    ((size_of_read_data ) == header.image_size ) << std::endl;
    std::cout << "\tSize of header "<< header.i_file_size << ((header.i_file_size == 124) ? " (BITMAPV5HEADER)" : "") << std::endl;
    std::cout << "\tCompression used "<< header.compression << std::endl;
    std::cout << "\tsize_of_read_data "<< size_of_read_data << std::endl;
    std::cout << "\t image size "<< header.image_size << std::endl;
    // std::cout << "\t  "<< header.image_size << std::endl;
    
    

    if(header.compression != 0){
        error("Cannot decompress images, yet! Please try uncompressed image");
    }
  // * == modification of the image == *
    uint8_t *buff_data_layer_gray = new uint8_t[MAX_FILE_SIZE];
    uint8_t *buff_data_layer_blur = new uint8_t[MAX_FILE_SIZE];

//   std::cout <<"working on grey scale filter" << std::endl;
//   for(int i =0;i <size_of_read_data;++i){
//     long long base = i*3;
//     if(base+2 <=size_of_read_data){
//       uint8_t gray = 0.299 * buff_data[base+2] + 0.587 * buff_data[base+1]  + 0.114 *  buff_data[base+0];
//       buff_data[base+2] = gray;
//       buff_data[base+1] = gray;
//       buff_data[base+0] = gray;
//     }
// //   }
//     std::cout << "working on blur filter." << std::endl;
  
//     auto time = std::chrono::high_resolution_clock::now();    
//     gaussianBlur15x15_SLOW(buff_data,buff_data_layer_blur,header.width,header.height);
//     auto dur = std::chrono::high_resolution_clock::now() - time;    
    
    std::cout << "working on Gabor filter." << std::endl;

    // Gabor parameters
    int ksize   = 41;
    float sigma = 4.0f;
    float theta = M_PI / 2;    
    float lambda = 10.0f;
    float gamma  = 0.5f;
    float psi    = 0.0f;

    // generate kernel
    auto gaborKernel = makeGaborKernel(ksize, sigma, theta, lambda, gamma, psi);

    auto time = std::chrono::high_resolution_clock::now();
    applyGaborFilter(buff_data, buff_data_layer_blur, header.width, header.height, gaborKernel, ksize);
    auto dur = std::chrono::high_resolution_clock::now() - time;
    
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << "\tFinished in " << ms << " milliseconds."<< std::endl;
    
    time = std::chrono::high_resolution_clock::now();
    int numThreads = 8;
    std::vector<std::thread> threads;
    int radius = ksize / 2;

    int slice = header.height / numThreads;

    for (int i = 0; i < numThreads; i++) {
        int yStart = std::max(radius, i * slice);
        int yEnd   = std::min((int)(header.height - radius), (i + 1) * slice);

        threads.emplace_back(applyGaborFilterSection,
                            buff_data, buff_data_layer_blur,
                            header.width, header.height,
                            std::ref(gaborKernel),
                            ksize,
                            yStart, yEnd);
    }

    for (auto &t : threads)
        t.join();
     dur = std::chrono::high_resolution_clock::now() - time;

     ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << "\tFinished in " << ms << " milliseconds."<< std::endl;
    // * == save file == *
    
    int out_fd = open(OUTPUT_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0664);
    
    lseek(fd, 0, SEEK_SET);
    char buffer[255];

    size = read(fd, buffer,header.data_offset);
    
    write(out_fd, buffer, size);
    
    std::cout << "Writing to local file" << std::endl;
    // size = write(out_fd, buff_data, size_of_read_data);
    size = write(out_fd, buff_data_layer_blur, size_of_read_data);
    std::cout << "\tFile ready! Data written (bytes): " << size << std::endl;

        // * == clean up == *
    close(fd);
    close(out_fd);
    delete [] buff_data;
        
    return 0;
}
