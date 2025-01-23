#ifndef _Expressions_hpp__
#define _Expressions_hpp__

#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>



class Expression{

public:
    Expression() {};
    virtual ~Expression() {};
    virtual void Destruct() = 0;
    virtual Expression* clone() = 0;
    virtual std::ostream& print( std::ostream& stream ,const int tabs = 0) = 0;
};


class Associate_Exp : public Expression{

public:
    std::string func_name;
    Expression* expression;

    Associate_Exp(std::string function_name, Expression* expression) : func_name(function_name), expression(expression){}
    ~Associate_Exp() override {}
    Expression* clone() override {
        return new Associate_Exp(func_name, expression->clone());
    }
    void Destruct() override{
        if(this->expression)this->expression->Destruct();
        delete this;
    }
    std::ostream& print( std::ostream& stream, const int tabs = 0) override{
        stream << std::string(tabs, ' ') << func_name << "<-" << std::endl;
        this->expression->print(stream,tabs+1);
        return stream; 
    }
};


class Argument_Exp : public Expression{

public:

    std::size_t index;
    Argument_Exp(std::size_t _index) : index(_index) {}
    ~Argument_Exp() override {}

    void Destruct() override{
        index = -1;
        delete this;
    }
     Expression* clone() override{
        return new Argument_Exp(index);
    }
     std::ostream& print( std::ostream& stream, const int tabs = 0) override{
        stream << std::string(tabs, ' ') << "index: " << index << std::endl;
        return stream; 
    }
};


class Number_Exp : public Expression{

public:

    double value;
    Number_Exp(double _value) : value(_value) {}
    ~Number_Exp() override {}
    void Destruct() override{
        value = 0;
        delete this;
    }
    Expression* clone() override{
        return new Number_Exp(value);
    }
    std::ostream& print( std::ostream& stream, const int tabs = 0) override{
        stream << std::string(tabs, ' ') << value << std::endl;
        return stream; 
    }
};


class Function_Exp : public Expression{

public:
    std::string func_name;
    std::vector<Expression*> arguments;

    Function_Exp(std::string function_name, std::vector<Expression*>& arguments) : func_name(function_name), arguments(arguments) { };
    ~Function_Exp() override {}

    void Destruct() override{
        for(int i = 0;i <arguments.size();++i){
            if(arguments[i])arguments[i]->Destruct();
        }
        delete this;
    }
    Expression* clone() override{
        std::vector<Expression*> args(arguments.size());
        for(int i =0; i<args.size();++i){
            args[i] = arguments[i]->clone();
        }
        return new Function_Exp(func_name, args);
    }
    std::ostream& print( std::ostream& stream, const int tabs = 0) override{
        stream << std::string(tabs, ' ') << func_name << " " <<arguments.size() << std::endl;
        for(int i =0;i<arguments.size();++i){
            this->arguments[i]->print(stream,tabs+1);
        }
        return stream; 
    }
};


struct executeArgs{
    size_t argc = -1;
    Expression* function = nullptr;
};

typedef std::vector<Expression*> enviroment;

#endif // _Expressions_hpp__
