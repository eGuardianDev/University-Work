#ifndef _Heap__
#define _Heap__

#include <cmath>
#include <stdexcept>
class heap{

public:
    heap(): level(0) { data = new int[cap];}
    ~heap() {delete [] data;}

    int extractMin(){
        if(size == 0)throw std::underflow_error("Empty heap");

        if(size == 1){
            size = 0;
            return data[0];
        }


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
        return size ==0;
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
        int powerLevel = std::pow(2, ++level);
        data = new int[cap + powerLevel];
        cap += powerLevel;
        for(int i =0;i <powerLevel;++i){
            std::swap(temp[i], data[i]);
        }
        delete [] temp;
    }
    int left(unsigned int index){
        return (2*index)+1;
    }
    int right(unsigned int index){
        return (2*index)+2;
    }
    int parent(unsigned int index){
        return (index-1) /2;
    }

    void goUp(unsigned int index){
        while(index != 0 && data[index] < data[parent(index)]){
            std::swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }

    void goDown(unsigned int index){

        int l = left(index);
        int r = right(index);

        int min = index;
        if(l < size && data[min] > data[l]) 
        {
            min = l;
        }
        if(r < size && data[min] > data[r]) 
        {
            min = r;
        }

        if(min != index){
            std::swap(data[index], data[min]);
            goDown(min);
        }
    }

    int size = 0;
    int cap  = 1;
    int level = 0;

    int *data;

};

#endif