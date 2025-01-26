
#include "../headers/Parser.hpp"


Token &Parser::Peak(){
    if(index == objs.size()){
        problem("Uncomplete syntax " + std::to_string(index));
    }
    return objs[index];
}
Token &Parser::Pop(){
    return objs[index++];
}
bool Parser::end(){
    return index >= objs.size();
}
void Parser::next(){
    ++index;
}
void Parser::reset(){
    index = 0;
}
void Parser::problem(const std::string& data){
    std::string res;
    res += data +"\n\n";
    reset();
    throw std::runtime_error(res);
}

void Parser::Clean(){
    objs.clear();
    index =0 ;
}

Expression* Parser::build(std::vector<Token> _objs, int& _index){
    objs= _objs;
    index = _index;

    Expression* root = nullptr;
    while(!end()){
        switch(Peak().token){
            case Function:
            {
                std::string func_name = Peak().val;

                next();

                if(Peak().token == LetBe){

                    next();

                    root = new Associate_Exp(func_name, build(_objs,index));
                    return root;
                    
                }else if(Peak().token == Comma ){
                    next();
                    std::vector<Expression*> emptyArgs(0);
                    return new Function_Exp(func_name,emptyArgs);
                }
                else if(Peak().token == Open_bracket){

                    next();
                    std::vector<Expression*> args;

                    while(Peak().token != Close_bracket){
                        Expression* temp = build (objs,index);
                        
                        if(temp) args.push_back(temp);

                    }
                    next();

                    root = new Function_Exp(func_name,args);
                    return root;
                }else if( Peak().token == Close_bracket){
                    std::vector<Expression*> emptyArgs(0);
                    return new Function_Exp(func_name,emptyArgs);
                }

                break;
            }

            case Variable:
            {
                root = new Argument_Exp(std::stoi(Peak().val.data() + 1));
                next();
                return root;
                // break;
            }
            case Number:
            {
                root = new Number_Exp(std::stod(Peak().val)); 
                next();
                return root;
            }  
                // break;
            case Comma:
            case Close_bracket:
                next();
                return nullptr;
            case Open_bracket:
            case LetBe:
                throw std::logic_error("Detected token that shouldn't be passed - " + Peak().val);
            default:
                throw std::logic_error("Undefined token problem");
        }
    }
    return root;
}

Expression* Parser::build(std::vector<Token> _objs){
    int index =0;
    maxArgumnets = 0;
    Clean();
    return build(_objs,index);
}
