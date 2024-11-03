

#ifndef _SORTEST_LIST_HEADER__
#define _SORTEST_LIST_HEADER__

#include "./additional/DynArray.hpp"

template<class DataType>
class SortedList{

public:
    void add(const DataType& element);
    SortedList& operator+(DataType& element){
        add(element);
        return *this;
    }
    int find(const DataType& element) const;
    void remove(const size_t index) { this->array.remove(index);}
    

private:
    #include "sortedListProxy.inl"

public:
    bool isEmpty() {return array.isEmpty();}
    size_t getSize() {return array.getSize();}
    void clear() {array.clear();}

    
    const DataType& operator[](size_t index)const
        { return array[index]; }
    SortedListProxy operator[](size_t index)
        { return SortedListProxy(*this, index); }

private:
    void MoveUp(size_t index);
    void MoveDown(size_t index);

    fmi::sdp::DynArray<DataType> array;

};


    #include "sortedList.inl"

#endif // _SORTEST_LIST_HEADER__