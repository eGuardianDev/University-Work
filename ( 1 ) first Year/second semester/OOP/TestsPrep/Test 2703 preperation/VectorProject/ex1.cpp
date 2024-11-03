#include <iostream>
#include <ostream>


class Vector{
    private:
    double arr[20];
    int size =0;
    
    
    public:
    int getSize(){
        return this->size;

    }
    Vector(){
        
    }   
    Vector(double el){
        this->operator+=(el);
    }
    double& operator[](unsigned int i){
        if(i>=size){
            throw std::overflow_error("Out of bound");
        }
        return arr[i];
    }

    Vector& operator+=(double elem){
        if(size >=20)
        {
            return *this;
        }
        this->arr[size] = elem;
        this->size++;
        return *this;
    }
    Vector operator+(double elem){
        Vector ret = *this;
        if(size >=20){
            return ret;
        }
        ret.arr[size] = elem;
        ret.size++;
        return ret;
    }
    bool operator<(const Vector vec){
        return (this->size < vec.size); 
    }
    bool operator==(const Vector vec){
        return (this->size == vec.size); 
    }
};

class Sequence{
    private:
    double *arr;
    int size;
    
    void expand(){
        double * pointer = new double[this->size+1];
        for(int i= 0;i<this->size;i++){
            pointer[i] = arr[i];
        }
        delete [] arr;
        this->arr = pointer;
        this->size++;
    }
    void copy(const Sequence& seq){
        if(this->size > 0){ // just in case to not crash the program when used in constuctor;
            delete [] arr;
        }
        this->arr = new double[seq.size];
        for(int i =0;i <seq.size;i++){
            this->arr[i] = seq.arr[i];
        }
        this->size = seq.size;
    }

    public:
    Sequence(){
        this->arr = new double[0];
        this->size = 0;
    }
    Sequence(const Vector vec){
        this->arr = new double[0];
        this->size = 0;
        this->AddVector(vec);
    }
    Sequence(const Sequence& seq){
        if(this != &seq){
            copy(seq);
        }
    }
    ~Sequence(){
        delete [] this->arr;
    }

    Sequence& operator=(const Sequence seq){
        
        if(this == &seq){
            return *this;
        }
        copy(seq);
        return *this;

    }

    void AddVector(Vector vec){
        for(int i =0 ;i<vec.getSize(); i++){
            expand();
            arr[size-1] =vec[i];
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Sequence& f);

};

std::ostream& operator<<(std::ostream& os, const Sequence& f)
{
    for(int i =0;i<f.size;i++){
        os << f.arr[i];
        if(i < f.size-1) os << ' ';
    }
    return os;
}
int main(){

    Vector vec(5);
    vec = (vec + 1);
    Vector vec2;
    vec2 = (vec + 3);
    Sequence seq(vec);
    seq.AddVector(vec2);
    std::cout << seq << '\n';
    return 0;
}