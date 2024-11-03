
#pragma once 


#ifndef Dynamic_List_include__
#define Dynamic_List_include__
#include <cstddef>
template<class T>
class DynamicList{
    
    private:
    size_t size;
    size_t capacity; // !new
    T* list;

    public:
    //===============================================
    //Init
    explicit DynamicList(int capacity = 16);
    ~DynamicList();
    
    DynamicList(const DynamicList& other);
    DynamicList& operator=(const DynamicList& other);
    
    //Copy
    template<class OtherType>
    DynamicList(const DynamicList<OtherType>& other);
    template<class OtherType>
    DynamicList& operator=(const DynamicList<OtherType>& other);
    
    //Move
    DynamicList(DynamicList&& other);
    DynamicList& operator=(DynamicList&& other);


    //================================================
    //extension
    // !new
    template<class OtherType>
    DynamicList& operator+=(const DynamicList<OtherType>& other); 
    DynamicList& operator+=(const T& element); 


    ///============================================
    void append(const T& element);
    void remove(size_t index);

    
    T get(size_t index) const;
    bool contains(const T& element) const; // !new

    size_t getSize() const;
    bool isEmpty() const;
    size_t getCapacity() const ;  // !new
    void clear(); //!new

    //access 
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    private:
    //!new
    void resize(size_t newCap);
    void ensureSize(size_t size);

    //! Iterator
    // #include "DAIterator.cpp"

    // DynamicArrayIterator<T> begin() { return DynamicArrayIterator<T>(list); }
    // DynamicArrayIterator<T> end() {return DynamicArrayIterator<T>(list+size);}
};

#include "dynamicList.inl"

#endif
