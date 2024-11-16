

#ifndef __ADDITIONAL_STRUCTS_
#define __ADDITIONAL_STRUCTS_

template<class T>
struct Pair{
    T first, second;
    Pair (T _first, T _second) : first(_first), second(_second) {}
};

enum Legend{
    Person = 'O',
    Broken = 'B',
    valid = '.',
    invalid = 'F'
};


#endif