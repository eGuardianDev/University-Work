#include "../header/kheap.hpp"
#include <alloca.h>
#include <new>

// == public == 

kHeap::kHeap(int k): level(0), size(0) {
    if(k <=0){
        throw std::invalid_argument("Heap with zero or negative children isn't allowed");
    }     
    kVariable = k;
    allocateDataArr();
}
const Word kHeap::extractMin(){
    if(size == 0)throw std::underflow_error("Empty heap");
    Word res = data[0];
    
    data[0] = data[--size];
    goDown(0);
    
    return res;
}

const Word& kHeap::getMin() const {
    if(size == 0)throw std::underflow_error("Empty heap");
    return data[0];
}

void kHeap::insert(const Word& w){
    if(size == cap) resize();
    data[size] = w;
    goUp(size);
    ++size;
}

void kHeap::buildFromVector(std::vector<Word>& vector, bool ignoreZeroCountWords){
    destroy();

    if(ignoreZeroCountWords){
        for(int i =0;i<vector.size();++i){
            if(vector[i].count != 0)
                ++size;
            }
    }else size = vector.size();

    // kVariable
    cap = 1;
    while(cap <size){
        ++level;
        cap += std::pow(kVariable,level);
    }

    allocateDataArr();

    int index = 0;
    for(int i =0;i<vector.size();++i){
        if(ignoreZeroCountWords && vector[i].count == 0)continue;

        data[index++] = vector[i];
    }
    size = index;

    for(int i =(size-1)/kVariable;i>=0;--i){
        goDown(i);
    }
}


// == private == 

void kHeap::allocateDataArr(){
    try{
        if(cap == 0){
            cap = 1;
        }
        data = new Word[cap];    
    }catch(const std::bad_alloc& e){
        data = nullptr;
        cap = 0;
        level = 0;
        size = 0;
        throw e;
    }
}
void kHeap::resize(){
    Word *temp = data;
    ++level;
    cap += std::pow(kVariable,level);
    allocateDataArr();
    if(temp != nullptr){
        for(int i =0; i<size;++i){
            std::swap(temp[i],data[i]);
        }
    }
    delete [] temp;
}
void kHeap::destroy(){
    // * this is not needed, because no pointers are used
    // for(int i =0;i<size;++i){
        // data[i].Destruction();
    // }
    size = 0;
    cap = 0;
    level = 0;

    delete [] data;
    data = nullptr;
}
void kHeap::goUp(unsigned int index){
    while(index > 0 && data[index].val < data[parent(index)].val){
        std::swap(data[index],data[parent(index)]);
        index = parent(index);
    }
}

void kHeap::goDown(unsigned int index){
    int l = left(index);
    int r = right(index);
    int min = index;
    for(; l<=r && l<size;++l){
        if(data[l].val < data[min].val){
            min = l;
        }
    }

    if(index == min) return;

    std::swap(data[min], data[index]);
    goDown(min);

}