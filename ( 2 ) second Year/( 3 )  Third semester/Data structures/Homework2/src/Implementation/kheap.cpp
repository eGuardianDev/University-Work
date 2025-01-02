#include "../header/kheap.hpp"

// == public == 

kHeap::kHeap(unsigned int k): level(0) {
    if(k ==0){
        throw std::invalid_argument("Heap with zero children isn't allowed");
    }     
    kVariable = k;
    data = new Word[cap];
}
kHeap::~kHeap() {
    for(int i =0;i<size;++i){
        data[i].Destruction();
    }

    delete [] data;
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

// == private == 

void kHeap::resize(){
    Word *temp = data;
    ++level;
    cap +=  std::pow(kVariable,level);
    data = new Word[cap]; 
    for(int i =0; i<size;++i){
        std::swap(temp[i],data[i]);
    }
    delete [] temp;
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