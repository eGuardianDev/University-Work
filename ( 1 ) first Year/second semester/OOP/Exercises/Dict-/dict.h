#pragma once
#include <iostream>

template <typename K>
struct pair{
    K key;
    int value;
};

template <typename K>
class Histogram{
    private:
    pair<K>* elements;
    int size;
    public:
        Histogram();
        Histogram(const Histogram&);
        ~Histogram();
        Histogram& operator=(const Histogram&);
        int operator[](K key);
        Histogram operator+(const Histogram&);
        Histogram& operator+=(const Histogram&);
        template<K>
        friend std::ostream& operator<<(std::ostream , const Histogram<K>&);

};