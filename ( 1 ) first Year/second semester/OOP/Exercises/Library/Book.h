#pragma once
#include "Person.h"
class Book{


    char* name;
    char* author;
    int publishYear;
    bool taken;
    int takenCount;
    Person* currentlyTakenBy;

    public:
    Book(char* name, char* author, int year);

    int Take(Person *p);
    int GiveBack();

    char* getAuthor();
    void setAuthor(char* name);
    char* getName();
    void setName(char* name);
    int getpublishYear();
    void  setpublishYear(int year);

};