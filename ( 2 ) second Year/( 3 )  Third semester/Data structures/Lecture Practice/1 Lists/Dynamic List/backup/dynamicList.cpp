


#ifndef _Array_Template__
#define _Array_Template__
#include "dynamicList.hpp"
#include <stdexcept>

template<class DataType>
inline DynamicList<DataType>::DynamicList(int initcapacity) : list(nullptr), size(0), capacity(initcapacity) {
    if(initcapacity <=0){
        throw std::invalid_argument("Invalid initial capacity");
    }
    list = new DataType[initcapacity];
};
template<class DataType>
inline DynamicList<DataType>::~DynamicList(){
    delete[] list;
    list = nullptr;
}

//Copy
template<class DataType>
template<class OtherType>
inline DynamicList<DataType>::DynamicList(const DynamicList<OtherType>& other) : list(nullptr), size(other.getSize()), capacity(other.getCapacity())
{
    for(size_t i =0; i < size;i++){
        list[i] = other[i];
    }
}
template<class DataType>
template<class OtherType>
inline DynamicList<DataType>& DynamicList<DataType>::operator=(const DynamicList<OtherType>& other)
{
    //what is this &other
    if(this != &other){
        if(capacity < other.getCapacity()){
            clear();
            ensureSize(other.getCapacity());
        }
        for(size_t i = 0;i < this->size;i++){
            list[i] = other[i];      
        }
    }
    return *this;
}

//Move
template<class DataType>
inline DynamicList<DataType>::DynamicList(DynamicList&& other) : list(nullptr), size(other.getSize()), capacity(other.getCapacity()){
    std::swap(list, other.list);
    // !allocator swap also*;
}


template<class DataType>
inline DynamicList<DataType>& DynamicList<DataType>::operator=(DynamicList<DataType>&& other){
    if(this != &other){
        std::swap(list,other.list);
        std::swap(size,other.size);
        std::swap(capacity,other.capacity);
        //! allocator   
    }
    return *this;
}


//================================================
//extension
// !new
template<class DataType>
template<class OtherType>
inline DynamicList<DataType>& DynamicList<DataType>::operator+=(const DynamicList<OtherType>& other){
    ensureSize(size + other.size);
    for(size_t i = 0;i<other.size;i++){
        this->append(other[i]);
    }
    return this;
} 

template<class DataType>
inline DynamicList<DataType>& DynamicList<DataType>::operator+=(const DataType& element){  
    ensureSize(size +1);
    this->append(element);

    return *this;
} 


///============================================
template<class DataType>
inline void DynamicList<DataType>::append(const DataType& element){
    ensureSize(size+1);
    this->list[size] = element;
    ++size;
}
template<class DataType>
inline void DynamicList<DataType>::remove(size_t index){
    if(index >= size){
        throw std::invalid_argument("Out of scope selection");
    }

    for(size_t i =index;i<size-1;++i){
        list[i] = list[i+1];
    }
    --size;
}

template<class T>
inline T DynamicList<T>::get(size_t index) const{
    if(index >= size){
        throw std::invalid_argument("Out of scope selection");
    }
    return list[index];
}
template<class T>
inline bool DynamicList<T>::contains(T& element) const{
    for(size_t i = 0;i <size;++i){
        if(element == list[i]) return true;
    }
    return false;
} // !new

template<class T>
inline size_t DynamicList<T>::getSize() const {return size;}

template<class T>
inline bool DynamicList<T>::isEmpty() const {return (size == 0);}

template<class T>
inline size_t DynamicList<T>::getCapacity() const {return capacity;}
    // !new
template<class T>
inline void DynamicList<T>::clear(){
    for(int i =0;i<size;++i){
        // delete list[i];
    }
    size = 0;
    list = nullptr;
} //!new

//access 
template<class T>
inline T& DynamicList<T>::operator[](size_t index){
    if(index >= size){
        throw std::invalid_argument("Out of bound selection");
    }
    return list[index];
}
template<class T>
inline const T& DynamicList<T>::operator[](size_t index) const{
    if(index >= size){
        throw std::invalid_argument("Out of bound selection");
    }
    return list[index];
}

//!new
template<class T>
inline void DynamicList<T>::resize(size_t newCap){
    T* temp = new T[newCap];
    for(size_t i =0;i<size;++i){
        temp[i] = list[i];
    }
    
    for(size_t i = 0;i <size;++i){
        // delete list[i];
    }
    list = temp;
    capacity = newCap;
    
}
template<class T>
inline void DynamicList<T>::ensureSize(size_t size){
    if(this->size >= capacity) return;
    int tempVal = 1;
    while(tempVal < size){
        tempVal *= 2;
    }
    resize(tempVal);
}


// without this it won't work
template class DynamicList<int>;
#endif
