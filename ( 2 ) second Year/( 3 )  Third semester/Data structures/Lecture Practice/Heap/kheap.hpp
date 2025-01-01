
#ifndef _KHeap_HPP__
#define _KHeap_HPP__

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
        data = new int[cap];
    }
    ~kHeap() {delete [] data;}

    int extractMin(){
        if(size == 0)throw std::underflow_error("Empty heap");
        int res = data[0];
        
        data[0] = data[--size];
        goDown(0);
        
        return res;
    }

    int getMin(){
        if(size == 0)throw std::underflow_error("Empty heap");
        return data[0];
    }

    int Size(){
        return size;
    }
    int isEmpty(){
        return size == 0;
    }

    void insert(int val){
        if(size == cap) resize();
        data[size] = val;
        goUp(size);
        ++size;
    }
    const int& returnCap(){
        return cap;
    }

    int*& getHeap(){
        return data;
    }

private:
    void resize(){
        int *temp = data;
        ++level;
        cap +=  std::pow(kVariable,level);
        data = new int[cap]; 
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
        while(index > 0 && data[index] < data[parent(index)]){
            std::swap(data[index],data[parent(index)]);
            index = parent(index);
        }
    }
    void goDown(unsigned int index){
        int l = left(index);
        int r = right(index);

        int min = index;
        for(; l<r && l<size;++l){
            if(data[l] < data[min]){
                min = l;
            }
        }

        if(index == min) return;

        std::swap(data[min], data[index]);
        goDown(min);

    }

    int size = 0;
    int cap  = 1;
    int level = 0;

    int kVariable = 2;

    int *data;


};

#endif //_KHeap_HPP__ 