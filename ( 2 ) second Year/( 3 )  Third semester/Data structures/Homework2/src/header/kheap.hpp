
#ifndef _KHeap_HPP__
#define _KHeap_HPP__

#include "./wordStruct.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

class kHeap{

public:
    kHeap(int k=2);
    ~kHeap(){destroy();}

    kHeap(kHeap &) = delete;
    kHeap &operator= (kHeap &) = delete;
    kHeap(kHeap &&) = delete;
    kHeap &operator= (kHeap &&) = delete;

    const Word extractMin();
    const Word& getMin() const;
    void insert(const Word&);

    const int& Size() const { return size; }
    const bool isEmpty() const { return size == 0; }
    const int& returnCap() const { return cap; }

    void buildFromVector(std::vector<Word>&, bool ignoreZeroCountWords = true);

private:
    void resize();

    void allocateDataArr();

    // * this is called destory, because it deletes the whole array, it's not just cleaning.
    void destroy(); 

    int left(const unsigned int index) const {return index*kVariable +1;}
    int right(const unsigned int index) const { return (index+1)*kVariable; }
    int parent(const unsigned int index) const {return (index -1)/kVariable;}

    void goUp(const unsigned int index);
    void goDown(const unsigned int index);

    int size = 0;
    int cap  = 1;
    int level = 0;

    int kVariable = 2;
    Word *data;

};

#endif //_KHeap_HPP__ 