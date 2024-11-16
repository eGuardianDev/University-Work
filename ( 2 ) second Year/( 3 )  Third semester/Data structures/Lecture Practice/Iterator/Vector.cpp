
#include "Vector.h"


const int& Vector::operator[](unsigned const int index) const{
    return this->data[index];
}
int& Vector::operator[](unsigned int index){
    return this->data[index];
}

const int Vector::append(const int data){
    this->data[size] = data;
    ++size;
    return (size-1);
}


