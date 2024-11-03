


#ifndef _SORTED_LIST_IMPLEMENTATION__
#define _SORTED_LIST_IMPLEMENTATION__

#include "sortedList.hpp"

template<class DataType>
inline void SortedList<DataType>::add(const DataType& element){
    this->array.append(element);
    MoveUp(this->array.getSize()-1);
}

template<class DataType>
inline int SortedList<DataType>::find(const DataType& element) const{
    size_t left = 0, right = this->array.getSize(), middle = 0;

    while(left < right){
        middle = left + (right-left)/2;
        const DataType& selected = this->array[middle]; 
        if(selected < element) left = middle +1;
        else if(element < selected) right = middle;
        else return (int)middle;
    }
    return -1;
}

template<class DataType>
inline void SortedList<DataType>::MoveUp(size_t index){
    if(index == 0 || this->array[index-1] < this->array[index] ){
        return;
    }
    
    DataType data = this->array[index];
    while(index > 0 && this->array[index-1] > data){
        this->array[index] = this->array[index-1];
        --index; 
    }
    this->array[index] = data;
}

template<class DataType>
inline void SortedList<DataType>::MoveDown(size_t index){
    if(index == this->array.getSize() || this->array[index] < this->array[index+1]){
        return;
    }

    int size = this->array.getSize()-1;
    DataType data = this->array[index];

    while(index < size || array[index] > array[index-1]){
        array[index] = array[index+1];
        ++index;
    }

    this->array[index] = data;
}

#endif // _SORTED_LIST_IMPLEMENTATION__