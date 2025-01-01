
#ifndef _KHeap_HPP__
#define _KHeap_HPP__

#include "wordStruct.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
class kHeap{

public:
    kHeap(unsigned int k=2): level(0) {
        if(k ==0){
            throw std::invalid_argument("Heap with zero children isn't allowed");
        }     
        kVariable = k;
        data = new Word[cap];
    }
    ~kHeap() {
        for(int i =0;i<size;++i){
            data[i].Destruction();
        }

        delete [] data;
    }

    Word extractMin(){
        if(size == 0)throw std::underflow_error("Empty heap");
        Word res = data[0];
        
        data[0] = data[--size];
        goDown(0);
        
        return res;
    }

    Word getMin(){
        if(size == 0)throw std::underflow_error("Empty heap");
        return data[0];
    }

    int Size(){
        return size;
    }
    int isEmpty(){
        return size == 0;
    }

    void insert(Word w){
        if(size == cap) resize();
        data[size] = w;
        goUp(size);
        ++size;
    }

    const int& returnCap(){
        return cap;
    }

private:
    void resize(){
        Word *temp = data;
        ++level;
        cap +=  std::pow(kVariable,level);
        data = new Word[cap]; 
        for(int i =0; i<size;++i){
            std::swap(temp[i],data[i]);
        }
        delete [] temp;
    }
    int left(unsigned int index){
        return index*kVariable +1;
    }
    int right(unsigned int index){
        return (index+1)*kVariable;
    }
    int parent(unsigned int index){
        return (index -1)/kVariable;
    }

    void goUp(unsigned int index){
        while(index > 0 && data[index].val > data[parent(index)].val){
            std::swap(data[index],data[parent(index)]);
            index = parent(index);
        }
    }
    void goDown(unsigned int index){
        int l = left(index);
        int r = right(index);

        int max = index;
        for(; l<r && l<size;++l){
            if(data[l].val > data[max].val){
                max = l;
            }
        }

        if(index == max) return;

        std::swap(data[max], data[index]);
        goDown(max);

    }

    int size = 0;
    int cap  = 1;
    int level = 0;

    int kVariable = 2;

    Word *data;


};

#endif //_KHeap_HPP__ 