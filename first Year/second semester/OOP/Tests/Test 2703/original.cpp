
#include <iostream>
#include <stdexcept>


class Statistics{

    private:
    int _num;
    int _sum;
    int _prod;
    int _max;
    double _avarage;
    
 

    public:
    Statistics(){
       _num = 0;
       _sum =0;
       _prod = 1;
        _max = 0;
        _avarage = 0;
    }
    int sum(){
        return _sum;
    }
    int num(){
        return _num;
    }
    int prod(){
        return _prod;
    }
    int max(){
        return _max;
    }
    double average(){
        return _avarage;
    }
    void Add(int number){
        _num++;
        _sum += number;
        _prod *= number;
        if(number > _max) _max = number;
        _avarage = (double)_sum/_num;
    }
    
    Statistics operator+(int number){
        Statistics st = *this;
        st.Add(number);
        return st;
    }
    Statistics& operator+=(int number)
    {
        this->Add(number);
        return *this;   
    }
};

template<typename T>
class BoundSet{
    private:
    T* arr;
    int maxSize; 
    int currentSize;

    void throwDiffArrError(){
        throw std::invalid_argument("Trying to copy objects with diffrent array sizes");
    }
    void copy(const BoundSet& other){
        if(this->currentSize > 0){
            delete [] this->arr;
        }
        arr = new T[other.maxSize];
        for(int i = 0 ;i< other.currentSize; i++){
            this->arr[i] = other.arr[i];
        }
        this->currentSize = other.currentSize;
    }

    public:
    BoundSet(int size){
        this->maxSize = size;
        this->arr = new int[size];
        currentSize = 0;
    }   


    //dynamic memory copy 
    BoundSet(const BoundSet& other){
        
        if(this->maxSize == 0 || other.maxSize == this->maxSize){
            copy(other);
        }else{
          throwDiffArrError();

        }
    }
    ~BoundSet()
    {
        delete [] this->arr;
    }
    

    BoundSet& operator+=(const BoundSet& other){
        if(other.maxSize != this->maxSize){
            throwDiffArrError();
        }
        if(other.currentSize > this->maxSize - this->currentSize){
            return *this;
        }
        for(int i =0 ;i<other.currentSize;i++){
            this->add(other[i]);
        }
        return *this;
    }
    
    BoundSet operator+(const BoundSet& other){

        // ! this doesn't work for some reason
        // only when I add "&" after Boundset in the return type it works.
        // I know it has something to do with copy constructor, but cannot figure out why it throws exceptions.
        // If it doesn't throw this exception is says free null pointer
        BoundSet l = *this;
        if(other.maxSize != l.maxSize)
        { throwDiffArrError();}
        if(other.currentSize > l.maxSize-l.currentSize){
            return l;
        }
        for(int i =0 ;i<other.currentSize;i++){
            l.add(other.arr[i]);
        }
        return l;
    }

    //dynamic memory helper
    BoundSet& operator=(const BoundSet& other){
        if(this == &other){
            return *this;
        }
        if(other.maxSize == this->maxSize){
            copy(other);
        }else{
            throwDiffArrError();
        }
        return *this;
    }



    // ! This operator only allows reading and NOT writing
    // ! This is how I want it to be
    T operator[](unsigned int i) const {
        if(i > this->maxSize){
            throw std::overflow_error("Index out of array");
        }
        return this->arr[i];
    }
    int size(){
        return this->currentSize;
    }
    //basic functions
    void add(const T element){
        if(this->currentSize == this->maxSize) return;
        if(this->member(element) == true) return;
        this->arr[this->currentSize++] = element;
    }
    void remove(const T element){
        if(currentSize == 0)return;
        if(!this->member(element))return;

        int index = -1;
        for(int i = 0;i<this->currentSize;i++){
            if(this->arr[i]== element){
                //set flag;
                index = i;
                break;
            }
        }
        this->currentSize--;
        for(int i = index;i<this->currentSize;i++ ){
            this->arr[i] = this->arr[i+1]; 
        }


    }
    bool member(const T element) const{
        for(int i =0; i < this->currentSize; i++){
            if(this->arr[i] == element){
                return true;
            }
        }
        return false;
    }
};


int main(){

    //example

    BoundSet<int> a(5);
    a.add(3);
    BoundSet<int> b(5);
    b.add(1);
    b.add(2);
    b = a;
    b = b+a;
    // b + a; <- this doesn't work...
    for(int i =0;i<b.size();i++){
        std::cout << b[i] << " ";
    }
    return 0;
}