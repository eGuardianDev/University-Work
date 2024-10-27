#pragma once

#include<iostream>

class Person{

    char* name;
    int age;
    char gender;
    
    public:
    Person(char*, int,char );
    char* getName();
    void setName(char*);
    int getAge();
    void setAge(int);
    void setGender(char);
    char getGender();

    void operator=(Person&);
    
    friend std::ostream& operator << (std::ostream, Person* );
};