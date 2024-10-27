#pragma once
#include "Book.h"
#include "Person.h"
class Library{

    private:
        Person** librarian;
        Person** Reader;
        Person* Books;
        
    public:
        Library();

        void AddLibrarian(Person p);
        void RemoveLibrarian(Person p);
        
        void AddReader(Person p);
        void RemoveReader(Person p);
        
        void AddBook(Person p);
        void RemoveBook(Person p);
        




};