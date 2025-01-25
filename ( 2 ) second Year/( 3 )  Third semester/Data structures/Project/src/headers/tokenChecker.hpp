
#include <stdexcept>
#include <vector>

#include "./Tokens.hpp"


class tokenChecker{
    private:

    std::vector<Token> objs;
    int index = 0;

    Token &Peak(){
        if(index == objs.size()){
            problem("Uncomplete syntax");
        }
        return objs[index];
    }
    Token &Pop(){
        return objs[index++];
    }
    bool end(){
        return index == objs.size();
    }
    bool canContinue(){
        return index != objs.size();
    }
    void next(){
        ++index;
    }

    void reset(){
        index = 0;
    }

    std::string getTokensUntil(const int n, int &count){
        if(n > objs.size()) throw std::logic_error("Trying to display tokens outside of size bound");  
        std::string res;
        for(int i =0;i<objs.size();++i){
            if(i < n) count += (objs[i].val.size());
            res += objs[i].val;
        }
        return res;
        
    }
    void problem(const std::string& data){
        int offset = 0;
        std::string res;
        res += data +"\n\n";
        res += " " + getTokensUntil(index,offset) +'\n';
        res += std::string(offset+1, ' ') + "^-- here\n";
        // std::cout << "at index: " << index << std::endl;
        reset();
        // std::cout << getTokensUntil(index) << '\n';
        throw std::runtime_error(res);
    }

    public:

    tokenChecker(){}
    ~tokenChecker(){}
    tokenChecker(tokenChecker&)  = delete;
    tokenChecker& operator=(tokenChecker&) = delete;
    tokenChecker(tokenChecker&&)  = delete;
    tokenChecker& operator=(tokenChecker&&) = delete;

    bool check(std::vector<Token> _objs, int _index = 0){
        objs = _objs;
        index = _index;
        if(objs.size() == 0){
            throw std::logic_error("Empty vector | no tockens passed");
        }

        bool endedFunction = false;
        bool afterLetBe = false;
        int bracketCount = 0;
        while(!end()){
            if(endedFunction){
                problem("Multiple definions on one line");
            }
            switch(Pop().token){
                case Function:
                    if(bracketCount == 0){
                        if(Peak().token != LetBe && Peak().token != Open_bracket){
                            problem("Expected parsing or calling of function");
                        }
                    }
                    break;
                
                case Open_bracket:
                    if(index == 1){
                        problem("Calling nothing - expected var behind brackets");
                    }
                    if(Peak().token == Open_bracket){
                        problem("Too many open brackets");
                    }
                    if(Peak().token != Variable && Peak().token != Function 
                    && Peak().token != Number && Peak().token != Close_bracket){
                        problem("Expected variable or number inside bracket");
                    }
                    ++bracketCount;
                    break;
                
                case Close_bracket:
                    if(bracketCount ==0){
                        problem("too many closing brackets");
                    }
                    --bracketCount;
                    if(bracketCount ==0)
                        endedFunction = true;
                    break;
                
                case Comma:
                    if(bracketCount == 0){
                        problem("Comma outside brackets");
                    }
                    if(Peak().token != Variable && Peak().token != Function && Peak().token != Number){
                        problem("Expected variable or number");
                    }
                    break;

                case LetBe:
                    if(index == 1){
                        problem("Trying to define something, but no name given");
                    }
                    if(bracketCount >0){
                        problem("Cannot define something inside argument input");
                    }
                    if(Peak().token != Variable && Peak().token != Function && Peak().token != Number){
                        problem("Expected function call or Number declaration after definition (<-)");
                    }
                    afterLetBe = true;
                    break;

                case Number:
                    if(canContinue() && (Peak().token == LetBe || Peak().token == Open_bracket)){
                        problem("Invalid operation over number");
                    }
                    break;  
                case Variable:
                    if(!afterLetBe){
                        index--;
                        problem("Trying to used variables definition outside defining scope");
                    }
                    if(bracketCount ==0){
                        problem("Cannot put variables outside brackets");
                    }
                    if(canContinue() && (Peak().token == LetBe || Peak().token == Open_bracket)){
                        problem("Invalid operation over number");
                    }
                    break;
                
                
                default:
                    reset();
                    throw std::logic_error("Undefined token type");
                    break;
            }
        }
        if(bracketCount>0){
            problem("Too many opening brackets");
        }


        return true;
    }

};