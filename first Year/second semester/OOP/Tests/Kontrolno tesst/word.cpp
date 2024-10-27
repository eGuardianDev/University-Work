#include "word.h"
#include <stdexcept>

// * initializator

Word::Word(){
    this->lenght = 0;
    this->characters[0] = '\0';
}
Word::Word(char c){
    this->lenght = 0;
    this->operator+=(c);
}
Word::Word(char* c){
    lenght = 0;
        int index = 0; 
    for(int i =0 ;i<21;i++){
        if(c[i] != '\0'){

            lenght++;
            this->characters[i] = c[i];
        } else break;
    }
}

// * operators

char& Word::operator[](unsigned int i) {
    if(lenght ==0){
        throw std::invalid_argument("No arguments in the word");
    }
    if(i >= lenght){
        throw std::invalid_argument("Out of bound");
    }
    return this->characters[i];
}
Word& Word::operator+=(char c){
    int l = this->getLenght();
    if(l > 20)
    {
        return *this;
    }
    this->characters[l] = c;
    this->lenght++;
    return *this;
}

Word Word::operator+(char c){
    this->operator+=(c);
    return *this;
}

bool Word::operator==(const Word& w) const{
    if(this->getLenght() != w.lenght) return false;

    for(int i =0 ;i<this->getLenght();i++){
        if(this->characters[i] != w.characters[i]){
            return false;
        }
    }
    
    return true;
}

int Word::getLenght() const{
    return this->lenght;
}

bool operator<(const Word& a,const Word& b){
    return (a.getLenght() < b.getLenght());
}

std::ostream& operator<<(std::ostream& out, const Word& w){
    for(int i= 0;i<w.getLenght(); i++){
        out << w.characters[i];
    }   
  return out;
}