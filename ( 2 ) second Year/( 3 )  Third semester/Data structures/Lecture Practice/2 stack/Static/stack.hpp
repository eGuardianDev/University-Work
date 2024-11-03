
#ifndef _STACK_HEADER__
#define _STACK_HEADER__


#include <cstddef>
class stack{

    private:
    int* data;
    // int* tos; // *this is not a pointer
    // size_t size //* not used
    size_t capacity, tos;

    public:
    stack(size_t cap = 16);
    ~stack();

    //! missed copy constructor
    stack(const stack& other);
    stack& operator=(const stack& other);


    const int& top() const;
    //* returns int because is building lightweight structure 
    int& pop();
    void push(const int& element);

    bool isEmpty() const;
    bool isFull() const; //! missed this
    // size_t getSize() const;
    // size_t getCapacity() const; // * doesnt need this



};
#endif 