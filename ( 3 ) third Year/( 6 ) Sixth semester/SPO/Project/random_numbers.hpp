#ifndef RANDOM_NUMBERS_HPP
#define RANDOM_NUMBERS_HPP

#include <cstdint>

class number_generator {
public:
    explicit number_generator(uint64_t seed)
        : state(seed ? seed : 0x123456789abcdefULL) {}

    // xorshift64*
    uint64_t next() {
        uint64_t x = state;
        
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;

        state = x;
        return x * 2685821657736338717ULL;
    }

    int next_int(int min, int max) {
        uint64_t r = next();
        return min + (r % (max - min + 1));
    }

private:
    uint64_t state;
};

#endif //RANDOM_NUMBERS_HPP
