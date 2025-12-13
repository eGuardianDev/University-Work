#ifndef ALGORITHMS_HPP__
#define ALGORITHMS_HPP__

#include <cstdint>
#include <cmath>

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
void Algo_Sobel_Edge(uint8_t* src, uint8_t* dst, int width, int height)
{
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
                    int idx = (py * width + px) * 3;

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

            int out = (y * width + x) * 3;
            dst[out + 0] = magB;
            dst[out + 1] = magG;
            dst[out + 2] = magR;
        }
    }
}



#endif // ALGORITHMS_HPP__