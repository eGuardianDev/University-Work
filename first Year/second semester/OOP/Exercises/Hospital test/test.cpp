//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>

class Person{

    public:

        Person(char* name, int age, char gender){
            this->name = new char[strlen(name)];
            strcpy(this->name,name);
            this->age = age;
            this->gender = gender;
        }
        Person(){

        }

        Person( const Person& p){
            copy(p);
        }


        ~Person(){
            del();
        }

        char* getName(){
            return name;
        }
        void setName(char* name){
            this->name = new char[strlen(name)];
            strcpy(this->name, name);
        }
        
        int getAge(){
            return this->age;
        }
        void setAge(int age){
            this->age = age;
        }

        char getGender(){
            return this->gender;
        }
        void setGender(char g){
            this->gender = g;
        }

        Person& operator=(const Person& p){
            if(this != &p){
                delete [] this->name;
                copy(p);
            }
            return *this;
        }



    private:    
        friend std::ostream& operator<<(std::ostream& os, const Person& person);
        
        void del(){
            delete [] this->name;
            
        }

        void copy(const Person& p){
            this->name = new char[strlen(p.name)];
            strcpy(this->name,p.name);
            this->age = p.age;
            this->gender = p.gender;
        }

        char* name;
        int age;
        char gender;

};

class Queue{
    private:
        Person* people;
        int currentMax = 0;
        int max = 50;
    public:

        Queue(){
            people = new Person[max];
        }

        Queue(const Queue& p){
            this->people = new Person[max];
            this->currentMax = p.currentMax;
            this->max = p.max;
            for(int i =0 ;i < currentMax;i++){
                this->people[i] = p.people[i];
            }
        }
        ~Queue(){
            delete [] people;
        }

        void push(Person p){
            people[currentMax++] = p; 
        }
        int lenght(){
            return currentMax;
        }
        Person top(){
            return people[0];
        }
        Person pull(){
            
            if(currentMax == 0){
                return Person("",0,'a');
            }
            Person p = people[0] ;

    
            currentMax--;
            for(int i =0; i< currentMax;i++){
                people[i] = people[i+1];
            }


            return p;

        }
};


std::ostream & operator<<(std::ostream &os, const Person& p)
{   
    os<< p.name << " " << p.age<< " "<< p.gender;
    return os;
}



int main(){

    Person p1("John", 12, 'i');
    

    Person p2("asd",1,'i');

    
    Queue queue;
    
    queue.push(p1);
    queue.push(p2);
    Queue queue2(queue);
    
    std::cout <<queue.pull();
    std::cout <<queue2.pull();
    std::cout <<queue2.pull();



    return 0;
}