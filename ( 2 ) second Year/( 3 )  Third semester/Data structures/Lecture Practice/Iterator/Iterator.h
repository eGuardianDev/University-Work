

#ifndef __ITERATOR_
#define __ITERATOR_

class myIterator{

private:
    int* element;

public:
    myIterator(int* it) : element(it) {}
    int& operator*(){
        return *element;
    }
    int* operator->(){
        return element;
    }
    
    myIterator& operator++(){
        ++element;
        return *this;
    }
    
    myIterator& operator++(int){
        myIterator *temp = this;
        ++element;
        return *temp;
    }

    bool operator==(myIterator& other){
        return this->element == other.element;
    }
    bool operator!=(myIterator& other){
        return this->element != other.element;
    }

};


#endif