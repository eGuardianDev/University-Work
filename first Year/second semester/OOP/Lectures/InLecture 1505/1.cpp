#include <iostream>
class Set{
    public:
    virtual bool member(int)const = 0; 
    Set(){}
    Set(const Set &){}
    virtual ~Set() {}
    virtual Set* copy() = 0;
    virtual void save(std::ostream& )const = 0;

    friend  std::ostream& operator<< (std::ostream&out, const Set* &data){
        data->save(out);
        return out;
    }
};


class Singleton : public Set{

    int element = 0;
    public:
    bool member(int x) const override{
        return (x == element);
    }
    Singleton(int x){
        this->element = x;
    }
    Set* copy() override{
        return new Singleton(element);
    }
    void save(std::ostream&  out) const override{
        out << "{";
        out << element;
        out << "}";

    };

};


class EvenInts : public Set{
    public:
    bool member(int x) const override{
        if(x %2 ==0){
            return true;
        }
        return false;
    }
    Set* copy() override{
        return new EvenInts();
    }
    void save(std::ostream&  out) const override{
        out << "{";
        for(int i =0;i<12; i++){
            if(i%2==0)out << i << ',';
        }
        out << "\b}";


    };
};
class EmptySet : public Set{
    public:
    bool member(int x) const override{
        return false;
    }
    Set* copy() override{
        return new EmptySet();
    }
     void save(std::ostream&  out) const override{
        out << "{ }";
    };
};

class SetUnion : public Set{
    Set *class1;
    Set *class2;
    public:
    SetUnion(Set *c1, Set *c2){
        class1= c1->copy();
        class2= c2->copy();
    }
    Set* copy() override{
        return new SetUnion(this->class1, this->class2);
    }
    SetUnion(const SetUnion &other){

        this->class1 = other.class1->copy();
        this->class2= other.class2->copy();        
    }
    ~SetUnion() override{
           delete class1;
        delete class2;
    }
    bool member(int x) const override{
        return (class1->member(x) || class2->member(x));
    }
    void save(std::ostream&  out)const override{
        class1->save(out);
        out << " & ";
        class2->save(out);

    };

};


int main(){
    Set *randomSet = new Singleton(1);
    
    std::cout << randomSet->member(1);
    

    UnionSet = new EmptySet();
    
    Set *single2 = new Singleton(3);
    
    std::cout << single2;
    return 0;
}
