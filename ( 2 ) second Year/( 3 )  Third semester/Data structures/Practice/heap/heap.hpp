#pragma once



#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>
class MinHeap{

    typedef std::size_t index;

    public:
    MinHeap(){ init();}
    ~MinHeap() { Clear();}

    int Extract(){
        if(Size() == 0){
            throw std::underflow_error("empty heap");
        }
        int front = getFront();
        removeFront();
        return front;
    }
    int Peak(){
        if(Size() == 0){
            throw std::underflow_error("empty heap");
        }
        return getFront();
        
    }

    void Add(int value){
        data.push_back(value);
        Float(data.size()-1);
    }
    
    void buildFromVector(std::vector<int>& input){
        Clear();
        data = input;
        for(int i =Size()/2;i>=0;--i){
            Sink(i);
        }
    }

    std::size_t Size(){
        return data.size();
    }

    int Remove(index index){
        int val = data[index];
        data[index] = INT_MIN;
        Float(index);
        Extract();
        return val;
    }

    private:


    int getFront(){
        return data[0];
    }
    void removeFront(){
        data[0] = data[data.size()-1];
        data.pop_back();
        Sink(0);

    }
    void Sink(index index){
        int left = leftChild(index);
        int right = rightChild(index);

        int swap = index;
        if(left < Size() && data[swap] > data[left]){
            swap = left;
        }
        if(right < Size() && data[swap] > data[right]){
            swap = right;
        }

        if(swap != index){
            std::swap(data[index], data[swap]);
            Sink(swap);
        }
    }
    void Float(index index){
        while(index >0 && data[Parent(index)] > data[index]){
            std::swap(data[Parent(index)], data[index]);
            index = Parent(index);
        }
    }
    index Parent(index index){
        return (index-1)/2;
    }
    index leftChild(index index){
        return index*2+1;
    }
    index rightChild(index index){
        return index*2+2;
    }
    

    void init(){
        data = std::vector<int>(0);
    }
    void Clear(){
        data.clear();
    }
    private:
    std::vector<int> data;

};