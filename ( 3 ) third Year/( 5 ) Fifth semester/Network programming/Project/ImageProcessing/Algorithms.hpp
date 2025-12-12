#ifndef ALGORITHMS_HPP__
#define ALGORITHMS_HPP__

#include <cstdint>

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

#endif // ALGORITHMS_HPP__