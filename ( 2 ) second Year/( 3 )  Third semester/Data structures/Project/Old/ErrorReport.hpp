#ifndef _Error_Report_hpp__
#define _Error_Report_hpp__

#include <stdexcept>
#include <string>

class Error{


    void logic_err(std::string& data){
        throw std::logic_error(data);
    }

    void argument_err(std::string& data){
        throw std::invalid_argument(data);
    }

};

#endif //_Error_Report_hpp__