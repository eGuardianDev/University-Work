#ifndef RANDOM_NUMBERS_HPP
#define RANDOM_NUMBERS_HPP

#include <cstdint>
class number_generator{

public:
    number_generator(int seed) :
        seed_(seed){
    }
    int next_int(int min, int max) {
        seed_ = 1103515245 * seed_ + 12345;
            uint32_t random_val = (seed_ >> 16); 
        return min + (random_val % (max - min + 1));
    }
private:
    uint32_t seed_ = 0;
};


#endif // RANDOM_NUMBERS_HPP