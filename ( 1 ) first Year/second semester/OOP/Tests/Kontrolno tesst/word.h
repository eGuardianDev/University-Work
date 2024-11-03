#pragma once
#include <iostream>

class Word{
private:
    char characters[20];
    int lenght;

public:
    Word();
    Word(char);
    Word(char*);
    int getLenght() const;
    char& operator[](unsigned int) ;
    Word& operator+=(char);
    Word operator+(char);
    friend bool operator<(const Word&,const Word&);
    bool operator==(const Word&) const;
    friend std::ostream& operator<<(std::ostream& , const Word&);
};