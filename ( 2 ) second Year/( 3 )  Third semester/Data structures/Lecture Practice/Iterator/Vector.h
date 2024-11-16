

#ifndef __CUSTOM_VECTOR_
#define __CUSTOM_VECTOR_


class Vector{

private:
    int* data;
    int size;
    int capacity;
public:

    Vector(int capacity = 4) : data(new int[capacity]), size(0){this->capacity = capacity;}

    ~Vector(){
        delete [] data;
        size = 0;
        data =nullptr;
    }

    const int& GetSize(){
        return size;
    }

    const int& operator[](unsigned const int index) const;
    int& operator[](unsigned int index);


    const int append(const int data);

    #include "Iterator.h"

    myIterator begin() {
        return myIterator(data);
    }
    myIterator end() { 
        return myIterator(data+size);
    }
    myIterator begin() const{ 
        return myIterator(data);
        }
    myIterator end() const{
        return myIterator(data+size);
    }


};






#endif