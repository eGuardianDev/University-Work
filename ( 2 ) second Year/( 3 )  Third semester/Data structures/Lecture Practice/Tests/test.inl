
#include <iostream>

template<class T>
testClass<T>::testClass(T a){
    std::cout << a << std::endl;
}

template<class T>
void testClass<T>::print(T b){
    std::cout << "deez nuts" << b << std::endl;
}

template<class T>
testClass<T>::~testClass(){}
