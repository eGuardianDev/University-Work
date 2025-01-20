#ifndef _Nodes_hpp_
#define _Nodes_hpp_

#include <exception>
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

class Node{

    public:
    virtual ~Node() {};
    virtual Node* clone() = 0;
    virtual double operator()(std::vector<Node*>& args) = 0;
    virtual void Destruct() = 0;
};


struct executeArgs{
    short argc = -1;
    // Node* function = nullptr; 
    std::function<Node*(std::vector<Node*>)> function = nullptr;
};

class RealNum : public Node{
    private:
    double val;
    short index = -1;
    public:
    RealNum(double a,  short index= -1) :val(a), index(index){}; 
    ~RealNum() override {}
    Node* clone() override{
        return new RealNum(val, index);
    }
    double operator()(std::vector<Node*>& args) override{
        if(index >=0){
            return args.size();
            // return (*args[index])(args);
        }
        return val;
    }
    void Destruct() override{
        delete this;
    }
};

class Add : public Node{
    public:
    Node *a, *b;
     Add(){}
     Add(Node* a, Node* b) : a (a), b (b){}
    ~Add() override {}
    double operator()(std::vector<Node*>& args) override{
        return (*a)(args) + (*b)(args);
    }
    Node* clone() override{
        return new Add(a->clone(), b->clone());
    }
    void Destruct() override{
        if(a)a->Destruct();
        if(b)b->Destruct();
        delete this;
    }
};
class VariableHolder : public Node{
     public:
     std::vector<Node*> args;
     Node *index;
     VariableHolder(){}
     VariableHolder(std::vector<Node*>& args, Node* index) : 
     args(args), index (index){}
    ~VariableHolder() override {}
    double operator()(std::vector<Node*>& _args) override{
        return (*args[(*index)(_args)])(_args);
    }
    Node* clone() override{

        std::vector<Node*> res(args.size());
        for(int i=0; i < args.size();++i){
            res[i] = args[i]->clone();
        }
        return new VariableHolder(res, index->clone());
    }
    void Destruct() override{
        if(index)index->Destruct();
        // for(int i =0;i<args)
        delete this;
    }
};

class If : public Node{
     public:
    Node *logic, *t, *f;
     If(){}
     If(Node* logic, Node* t, Node* f) : logic(logic), t(t), f(f){}

    Node* clone() override{
        return new If(logic->clone(), t->clone(), f->clone());
    }
    ~If() override {}
    double operator()(std::vector<Node*>& args) override{
        if((*logic)(args) !=0 ){
            return (*t)(args);
        }else{
            return (*f)(args);
        }
    }
    void Destruct() override{
        if(logic)logic->Destruct();
        if(t)t->Destruct();
        if(f)f->Destruct();
        delete this;
    }
};
class Sub : public Node{
     public:
    Node *a, *b;
     Sub(){}
     Sub(Node* a, Node* b) : a (a), b (b){}
    ~Sub() override {}
    double operator()(std::vector<Node*>& args) override{
        return (*a)(args) - (*b)(args);
    }

    Node* clone() override{
        return new Sub(a->clone(), b->clone());
    }
    void Destruct() override{
        if(a)a->Destruct();
        if(b)b->Destruct();
        delete this;
    }
};
class Mul : public Node{
};
class Div : public Node{
};
class Pow : public Node{
};
class Custom : public Node{
    // public:
    // std::vector<Node*> args;
    //  Custom(Node* a ...) : a (a), b(b){
    //     throw std::runtime_error("Pow function not ready");
    //  }
    // ~Pow() override {}
    // double operator()(std::vector<Node*>& args) override{
    //     // throw std::runtime_error("Function not ready");
    //     // (*a)(),(*b)();
    // }
    // void Destruct() override{
    //     if(a)a->Destruct();
    //     if(b)b->Destruct();
    // }
};

class Sqrt : public Node{
};
class Sin : public Node{
};
class Cos : public Node{
};
class Eq : public Node{
};
class Le : public Node{
};
class Nand : public Node{
};
class list : public Node{
};
class head : public Node{
};
class tail : public Node{
};
class map : public Node{
};
class filter : public Node{
};

#endif //_Nodes_hpp_