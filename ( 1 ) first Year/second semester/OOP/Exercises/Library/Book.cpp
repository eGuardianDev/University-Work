
#include "Book.h"

Book::Book(char* name, char* author, int year){
    this->name = name;
    this->author = author;
    this->publishYear= year;
}


int Book::Take(Person *p){

    this->currentlyTakenBy = p;
    this->takenCount++;
    this->taken = true;
    return this->takenCount;
}

int Book::GiveBack(){

    this->currentlyTakenBy = nullptr;
    this->taken = false;
    return this->takenCount;
}


char* Book::getAuthor(){
    return this->author;
}
void Book::setAuthor(char* name){
    this->author = name;
}
char* Book::getName(){
    return this->name;
}
void Book::setName(char* name){
    this->name = name;
}
int Book::getpublishYear(){
    return this->publishYear;
}
void Book::setpublishYear(int age){
    this->publishYear = age;
}