#include "Person.h"
#include <stdio.h>
#include <string.h>

Person::Person(char* name, int age,char gender){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->age = age;
    this->gender = gender;
}

int Person::getAge(){
    return this->age;
}
void Person::setAge( int age){
    this->age =age;
}

void Person::setName(char* name){
    delete this->name;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

char* Person::getName(){
    return this->name;
}

void Person::setGender(char gender){
    this->gender = gender;
}
char Person::getGender(){
    return this->gender;
}

void Person::operator=(Person &person){
    this->setAge(person.getAge());
    this->setName(person.getName());
}

std::ostream& operator << (std::ostream& out, Person* p){
    out << p->getName() << " " << p->getAge();
    return out;
}