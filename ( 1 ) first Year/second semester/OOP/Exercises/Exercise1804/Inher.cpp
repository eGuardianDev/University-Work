#include <iostream>


class A{
    private:
    int a = 0;
    
    public:
    A(int a ){
     this-> a = a;
    }

    ~A(){
        std::cout << "Deleted A" <<std::endl;
    }
    A(A& A){
    }
    void print() const{
        std::cout << "A: " << a << std::endl;
    }
};

class B{
    private:
    int b = 0;
    
    public:
    B(int b ){
     this-> b = b;
    }

    ~B(){
        std::cout << "Deleted B" <<std::endl;
    }
    B(B& B){
    }
    void print() const{
        std::cout << "B: " << b << std::endl;
    }

};


class C : A,B {
    protected:
    
    public:
    C(int a, int b ) : A(a),B(b){}

    ~C(){
        std::cout << "Deleted C" <<std::endl;
    } 

    C(C& c) : A(c), B(c){}

    void print() const{
        A::print();
        B::print();
    }
};

int main(){
    
    A a(1);
    B b(2);
    C c(3,4);

    c.print();



    return 0;
}