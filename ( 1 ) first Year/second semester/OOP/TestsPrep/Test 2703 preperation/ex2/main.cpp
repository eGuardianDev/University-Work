
#include <iostream>

template<typename T>
class Array{
    private:
    T* elem;
    int size;
    int capacity;

    void copy(const Array& a)
    {
      //  delete[] this->elem;
        elem = new T[a.capcaity];
        for(int i =0 ; i< a.size;i++){
            elem[i] = a[i];
        }   
        this->capacity = a.capacity;
        this->size = a.size;
    }
    public:
    Array(): size (0), capacity(10){
        elem = new T[0];
    }
    ~Array(){
        delete[] elem;
    }
    Array(const Array& a)
    {
        if(this != &a){
            copy(a);
        }
    }

    T& operator[](unsigned int i){
        if(i>size ){
            throw std::overflow_error("too big") ;
        }
        return this->elem[i];
    }




};




int main(){

    Array<int> a;
    a[0] = 1;
    std::cout << a[0];



    return 0;
}