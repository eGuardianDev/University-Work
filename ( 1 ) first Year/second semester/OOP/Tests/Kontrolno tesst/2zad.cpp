#include <iostream>

#include "word.h"

class Sentance{

    private:
    char* arr;

    public:
    void del(){

    }
    void copy(){

    }
    void AddWord(Word w){

    }
    Sentance(){

    }
    Sentance(const Sentance& s){
        
        
    }
    ~Sentance(){
        delete [] arr;
    }

    friend std::ostream& operator<<(std::ostream& os, Sentance sentance);

};
std::ostream& operator<<(std::ostream& os, Sentance sentance){
    os << sentance.arr;
}


int main(){



    return 0;
}