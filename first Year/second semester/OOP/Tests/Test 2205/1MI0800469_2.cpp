#include <complex>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

class MathExpression{
    public:
    virtual double value() const = 0;
    virtual void print(std::ostream&) const = 0;
    virtual MathExpression* Clone() = 0;
    virtual ~MathExpression() {};
    
    // ! there was an attempt
    // virtual MathExpression* begin() = 0;
    // virtual MathExpression* end() = 0;
    // virtual size_t size() = 0;
    // virtual bool empty() = 0;
};

class Const : public MathExpression{
    double _value;
    public:
    Const(double value){
        this->_value = value;
    }
    Const(Const& c){
        this->_value = c.value();
    }
    MathExpression* Clone() override{
        return new Const(this->_value);
    }
    double value() const override{
        return this->_value;
    }
    void print(std::ostream& out) const override{
        out << this->_value;
    }
    // MathExpression* begin() {return nullptr;}
    // MathExpression* end() {return nullptr;}
    // size_t size() {return 0;}
    // bool empty() {return false;}
    ~Const() override {} // unneeded
};

class Min: public MathExpression{
    MathExpression* _min;
    public:
    Min(MathExpression* value){
        this->_min = value->Clone();
    }
    Min(double value1, double value2){
        if(value1 > value2)
         this->_min = new Const(value1);
        else 
         this->_min = new Const(value2);
    }
    
    Min(MathExpression* value1, MathExpression* value2){
        if(value1->value() < value2->value())
         this->_min = value1->Clone();
        else 
         this->_min = value2->Clone();
    }
    Min(Min& copied){
        this->_min = copied.Clone(); 
    }
    MathExpression* Clone() override{
        return new Min(this->_min);
    }
    double value() const override{
        return this->_min->value();
    }
    void print(std::ostream& out) const override{
        out << this->_min;
    }
    ~Min() override{
        delete _min;
    }
};
class Sum: public MathExpression{
    MathExpression** _sum;
    size_t Size;
    void expand(){
        MathExpression** temp = new MathExpression*[Size++];
        for(int i =0 ;i<Size-1;i++){
            temp[i] = this->_sum[i];
        }
        this->_sum = temp;
    }
    Sum(){}
    public:
    // MathExpression* begin(const MathExpression* T){
    //     return *_sum;
    // }
    //   constexpr MathExpression*
    //   begin() const noexcept { return *_sum; }
    // MathExpression* end(){
    //     return (MathExpression*)(_sum[this->Size-1]);
    //     // return (*_sum)+this->Size;
    // }
    // bool empty()
    // {
    //     if(end() == begin()) return true;
    //     return false;
    // }
    // size_t size(){
    //     return this->Size;
    // }
    
    // * There is some kind of List argument that input that i don't know about

    Sum(double value1 , double value2, double value3){
        this->addExpression(new Const(value1));
        this->addExpression(new Const(value2));
        this->addExpression(new Const(value3));
    }
    Sum(MathExpression* value1 , MathExpression* value2, MathExpression* value3){
        this->addExpression(value1->Clone());
        this->addExpression(value2->Clone());
        this->addExpression(value3->Clone());
    }
    Sum(double value1 , double value2) {
        this->addExpression(new Const(value1));
        this->addExpression(new Const(value2));
    }
    Sum(MathExpression* value1 , MathExpression* value2) {
        this->addExpression(value1->Clone());
        this->addExpression(value2->Clone());
    }
    


    MathExpression* Clone() override{
        Sum *s = new Sum();
        for(int i =0 ;i<Size;i++){
            s->addExpression(_sum[i]);
        }
        return s;
    }

    void addExpression(MathExpression* ob){
        expand();
        this->_sum[Size-1] = ob;
    }
    double value() const override{
        double toReturnSum = 0;
        for(int i =0;i<Size ;i++){
            toReturnSum += _sum[i]->value();
        }
        return toReturnSum;
    }
    void print(std::ostream& out) const override{
        out << this->value();
    }
    ~Sum() override{
        for(int i =0 ;i<Size;i++){
            delete _sum[i];
        }
        delete [] _sum;
    }



};

std::ostream& operator<<(std::ostream& out, MathExpression* expression){
    expression->print(out);
    return out;
}


int main(){
    // MathExpression* exp = new Min(1,2);
    MathExpression* exp = new Sum(new Min(new Const(1),new Sum(1,2)), new Sum(3,4,5),new Const(10));
    // for(MathExpression* item : exp){
    //     std::cout << item;
    // }



    std::cout << exp;
    return 0;
}