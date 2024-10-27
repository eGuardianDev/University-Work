

#ifndef _DYNAMIC_ITERATOR__
#define _DYNAMIC_ITERATOR__


#include <cstddef>
template<class DataType>
class DynamicArrayIterator{

    //friend class DynamicList
    DataType* pointer;

    DynamicArrayIterator(DataType* value) : pointer(value) {}

    public:

    // * selection
    DataType& operator->() {
        return pointer;
    }
    const DataType& operator->() const {
        return pointer;
    }
    
    DataType* operator*(){
        return *pointer;
    }
    const DataType* operator*() const{
        return *pointer;
    }

    // this here has to return value and not pointer so yea...
    DataType& operator[](size_t index){
        return *(pointer + index);
    }
    const DataType& operator[](size_t index) const {
        return *(pointer + index);
    }


    // * checking

    bool operator==(const DynamicArrayIterator& other){
    return (pointer == other.pointer);
    }
    bool operator!=(const DynamicArrayIterator& other){
    return (pointer != other.pointer);
    }
    bool operator>=(const DynamicArrayIterator& other){
    return (pointer >= other.pointer);
    }
    bool operator<=(const DynamicArrayIterator& other){
    return (pointer <= other.pointer);
    }
    bool operator>(const DynamicArrayIterator& other){
    return (pointer > other.pointer);
    }
    bool operator<(const DynamicArrayIterator& other){
    return (pointer < other.pointer);
    }



    // * movement
    DynamicArrayIterator& operator++(){
        ++pointer;
        return this;
    }
    DynamicArrayIterator operator++(int){
        DynamicArrayIterator send(*this);
        ++(*this);
        return send;
    }
    DynamicArrayIterator& operator+=(int index){
        pointer+=index;
        return this;
    }
    DynamicArrayIterator operator+(int index) const{
        DynamicArrayIterator send(*this);
        send+=index;
        return send;
    }
    

    DynamicArrayIterator& operator--(){
        --pointer;
        return pointer;
    }
    DynamicArrayIterator operator--(int){
        DynamicArrayIterator send(*this);
        --(*this);
        return send;
    }
    
};

#endif // _DYNAMIC_ITERATOR__