#ifndef _tokenChecker_hpp__
#define _tokenChecker_hpp__

#include <stdexcept>
#include <vector>

#include "./Tokens.hpp"


class tokenChecker{
    private:

    std::vector<Token> objs;
    int index = 0;

    Token &Peak();
    Token &Pop();
    bool end();
    bool canContinue();
    void next();

    void reset();

    std::string getTokensUntil(const int n, int &count);
    void problem(const std::string& data);

    public:

    tokenChecker(){}
    ~tokenChecker(){}
    tokenChecker(tokenChecker&)  = delete;
    tokenChecker& operator=(tokenChecker&) = delete;
    tokenChecker(tokenChecker&&)  = delete;
    tokenChecker& operator=(tokenChecker&&) = delete;

    bool check(std::vector<Token> _objs, int _index = 0);
};
#endif //_tokenChecker_hpp__
