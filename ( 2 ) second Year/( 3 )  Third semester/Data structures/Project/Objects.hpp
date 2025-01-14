#ifndef _Objects_hpp_
#define _Objects_hpp_

class Object{

    public:
    Object() {}
    virtual ~Object() {};
    virtual double operator()() = 0;
};


class RealNumber : public Object{
    private:
    double val;
    public:
    RealNumber(double a) :val(a){}; 
    ~RealNumber() override {}
    double operator()() override{
        return val;
    }
};

class AddFunc : public Object{


    public:
    Object *a, *b;
    AddFunc(){}
    AddFunc(Object* a, Object* b) : a (a), b (b){}
    ~AddFunc() override {}
   
    double operator()() override{
        return (*a)() + (*b)();
    }
};

class IfDef : public Object{


    public:
    Object *logic, *t, *f;
    IfDef() {}
    IfDef(Object* logic, Object* t, Object *f) : logic(logic), t(t), f(f){}
    ~IfDef() override {}
   
    double operator()() override{
        if((*logic)() != 0){
            return (*t)();
        }else{
            return (*f)();
        }
    }
};

class SubFunc : public Object{
};
class MulFunc : public Object{
};
class DivFunc : public Object{
};
class PowFunc : public Object{
};
class SqrtFunc : public Object{
};
class SinFunc : public Object{
};
class CosFunc : public Object{
};
class EqFunc : public Object{
};
class LeFunc : public Object{
};
class NandFunc : public Object{
};
class list : public Object{
};
class head : public Object{
};
class tail : public Object{
};
class map : public Object{
};
class filter : public Object{
};

#endif //_Objects_hpp_