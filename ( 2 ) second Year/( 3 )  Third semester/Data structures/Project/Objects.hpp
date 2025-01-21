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
    virtual Node* clone(std::vector<Node*>&) = 0;
    virtual double operator()(std::vector<Node*>& args ) = 0;
    virtual void Destruct() = 0;
};


struct executeArgs{
    int argc = -1;
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
    Node* clone(std::vector<Node*>& args ) override{
        return new RealNum(val, index);
    }
    double operator()(std::vector<Node*>& args ) override{
        if(index >=0){
            // return args.size();
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
    double operator()(std::vector<Node*>& args ) override{
        return (*a)(args) + (*b)(args);
    }
    Node* clone(std::vector<Node*>& args) override{
        return new Add(a->clone(args), b->clone(args));
    }
    void Destruct() override{
        if(a)a->Destruct();
        if(b)b->Destruct();
        delete this;
    }
};

class Wrapper : public Node{
    public:
    std::vector<Node*> args;
    Node* val;
    Wrapper(std::vector<Node*>& args, Node* val) : val(val){
        this->args = args;
    }
    ~Wrapper() override {}
    double operator()(std::vector<Node*>& args ) override{
        return (*args[0])(args);
    }
    Node* clone(std::vector<Node*>& _args) override{
        std::vector<Node*> res(args.size());
        for(int i=0; i < args.size();++i){
            res[i] = args[i]->clone(_args);
        }
        return val->clone(_args);
    }
    void Destruct() override{
        // if(index)index->Destruct();
        // for(int i =0;i<args)
        delete val;
        delete this;
    }
};

class VariableHolder : public Node{
     public:
     Node *index;
     VariableHolder(Node* index) : index (index){}
    ~VariableHolder() override {}
    double operator()(std::vector<Node*>& _args ) override{
        return (*_args[(*index)(_args)])(_args);
    }
    Node* clone(std::vector<Node*>& _args) override{
        return new VariableHolder(index->clone(_args));
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

    Node* clone(std::vector<Node*>& _args) override{
        return new If(logic->clone(_args), t->clone(_args), f->clone(_args));
    }
    ~If() override {}
    double operator()(std::vector<Node*>& args ) override{
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
    double operator()(std::vector<Node*>& args ) override{
        return (*a)(args) - (*b)(args);
    }

    Node* clone(std::vector<Node*>& _args) override{
        return new Sub(a->clone(_args), b->clone(_args));
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