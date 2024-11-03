#include <iostream>

using namespace std;

class Animal{
    public:
    virtual void Breathe() 
    {
        std::cout << "non" << endl;
    }
    virtual void Sound() =0;
    virtual ~Animal() {
        cout << "animal died" <<endl;
    }
};

class dog : public Animal{
    string name;
    public:
    dog(string n){
        this->name = n;
    }
    void Sound() override{
        cout << "Woof"<<endl;
    }
    ~dog() {
        cout << "dog died"<< endl;
    }
};
class cat : public Animal{
    string name;

    public:
    cat(string n){
        this->name = n;
    }
    void Sound() override{
        cout << "meow"<<endl;
    }
    ~cat() {
        std::cout << "cat died" << endl;
    }
};


int main(){

    Animal *animal = new dog("barker");
    
    animal->Sound();
    animal->Breathe();
    Animal *animal2 = animal.clone();
    // return new Animal*( new dog()) 
    delete animal;
    animal2->Sound();
    // dog doge = *dogeptr;
    // doge.Sound();
    return 0;
}