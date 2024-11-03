#include "stack.hpp"
#include <iostream>
#include <stdexcept>




    // int* data, tos;
    // size_t size, capacity;

    stack::stack(size_t cap) : capacity(cap){
        data = new int[cap];
        tos = 0;
    };
    stack::~stack(){
        delete [] data;
        capacity = 0;
        tos = 0;
        data = nullptr;
    }

    stack::stack(const stack& other){
        // if(this != &other){} //! impossible to parse unsaved value
        delete [] data;
        this->capacity = other.capacity;
        data = new int[capacity];
        for(size_t i =0; i< other.tos; ++i){
            data[i] = other.data[i];
        }
        tos = other.tos;
    }
    stack& stack::operator=(const stack& other){
        if(this != &other){
            tos = other.tos;
            this->capacity = other.capacity;
            for(size_t i =0; i< tos; ++i){
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    const int& stack::top() const{
        if(isEmpty()) throw std::underflow_error("trying to access empty stack");
        return data[tos-1];
    }

    int& stack::pop(){
        if(isEmpty()){
            throw std::underflow_error("trying to pop from empty stack");
        }
        int& toRet = *(data +tos-1);
        --tos;
        return toRet;
    }

    void stack::push(const int& element){
        if(isFull()){throw std::overflow_error("trying to push to full stack"); }
        data[tos++] = element;
        // ++tos;
    }

    bool stack::isEmpty() const{
        return (tos == 0);
    }
    bool stack::isFull() const{
        return (tos == capacity);
    }
    // size_t stack::getSize() const{
    //     return size;
    // } //* actualy not used??
    