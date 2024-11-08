#include <cassert>
#include <iostream>


template<class DataType>
class Particles{

DataType *data;

const size_t INTIAL_CAPACITY = 4;

size_t capacity;
size_t size;

void resize(){
    capacity*=2;
    DataType temp = new DataType[capacity];
    for(int i = 0; i<size;++i){
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
}
void ensureSize(size_t size){
    if(size == 0 || size < capacity){
        return;
    }
    if(this->size != capacity){
        resize();
    }
}

void MoveLeft(size_t index){
    for(size_t i = index ;i<size-1;++i){
        data[i] = data[i-1];
    }
}

public:
    //ctor
    Particles() : data(new DataType[INTIAL_CAPACITY]), size(0),capacity(INTIAL_CAPACITY) {}
    Particles(size_t size) : data(new DataType[size]), size(0),capacity(size) {}
    //dtor
    ~Particles(){
        delete [] data;
    }

    //copy
    Particles<DataType>(const Particles& other) : data(nullptr), size(other.size), capacity(other.capacity){
        data = new DataType[other.capacity];
        for(size_t i = 0;i<other.size;++i){
            data[i] = other.data[i];
        }
    }

    Particles<DataType>& operator=(const Particles& other){
        if(this != &other){
            delete [] data;
            size = other.data;
            capacity = other.capacity;
            for(size_t i = 0; i<size;++i){
                data[i] = other.data[i];
            }
        }
        return *this;
    } 

    //move semantics



    size_t add(const DataType& Element){
        ensureSize(++size);
        data[size-1] = Element;
    }

    void remove(size_t Id){
        
        
        // assert(Id >=0 && Id <size);
        MoveLeft(Id);
    } 
    const DataType& operator[](size_t Id){
        return data[Id];
    }

    /*
    int begin(){

    }

    int end(){

    }
    */


};




int main(){


    //test pointers in data type
    return 0;
}