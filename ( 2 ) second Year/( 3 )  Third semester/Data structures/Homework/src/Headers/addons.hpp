

#ifndef __ADDITIONAL_STRUCTS_H_
#define __ADDITIONAL_STRUCTS_H_

template<class T>
struct Pair{
    T first, second;
    Pair (T _first, T _second) : first(_first), second(_second) {}
};


// * Universal can change to whatever you want
enum Legend{
    Person = 'p',
    Broken = 'b',
    valid = '.',
    invalid = '-'
};


#endif