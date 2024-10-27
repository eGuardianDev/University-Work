
#include <iostream>
#include <vector>



class Person{

    protected:
    std::string name;
    int age;

    public:
    Person(){
        std::cout << " person was created " << std::endl;
    }

    Person(int age, std::string name) : age(age), name(name){
        std::cout << " person was created " << std::endl;
    }
    ~Person(){
        std::cout << " person was deleted " << std::endl;
    }

    std::string getName(){
        return this->name;
    }
    void setName(std::string name){
        this->name = name;
    }

    int getAge(){
        return this->age;
    }
    void setAge(int age){
        this->age = age;
    }



};

class Vehicle{
///fuel
//consumption
//driver
///brand

    protected:
    int fuel;
    double consumption;
    Person* driver;
    std::string brand;

    public:
    Vehicle(double consumption, Person* driver, std::string brand) :
     consumption(consumption), driver(driver),brand(brand){ fuel = 0;};

    int Fill(int x){
        this->fuel +=x;
        if(fuel > 20) this->fuel = 20;
        return this->fuel;
    }
    int Drain(int x){
        this->fuel -= x;
        if( fuel < 0) this->fuel = 0;
        return this->fuel;
    }

    void setDriver(Person* p){
        this->driver = p;
    }
    Person* getDriver(){
        return this->driver;
    }
    virtual bool isReachable(int distance){
        // consumption / 100
        // litter
        return (distance <= ((int)(100/this->consumption)*this->fuel));
        
    }


    ~Vehicle(){
        std::cout << this-> brand << " with " << this->driver->getName() << " in it, exploded" <<std::endl;
    }
    virtual int getCargo(){
        return 0;
    }
    virtual int getPassanger(){
        return 0;
    }


};

class CargoVehicle : public Vehicle{
    private:
    int capacity;
    int load;
    public:
    CargoVehicle(int capacity, int consumption, Person* driver, std::string brand):Vehicle(consumption,driver,brand){
        this->capacity = capacity;
        this->load = 0;
    }
    int addLoad(int l){
        load += l;
        if (capacity > 50) load = 50;
        return load;
    }
    int removeLoad(int l){
        load -= l;
        if (capacity < 0) load = 0;
        return load;
    }
 bool isReachable(int distance){
        // consumption / 100
        // litter
        int d = (int)this->fuel/(this->consumption*(1+(int)this->load/this->capacity));
        return (distance <= d);
        
    }
};

class PassangerVehicle : public Vehicle{
    private:
    int seats;
    std::vector<Person> passangers;
    public:
    PassangerVehicle(int seats, int consumption, Person* driver, std::string brand) : Vehicle(consumption, driver, brand){
        this->seats = seats;
    }
    int addPerson(Person x){
        if(this->passangers.size() == this->seats) return -1;
        this->passangers.push_back(x);
        return this->passangers.size();
    }

    int removeLastPerson(){
        this->passangers.pop_back();
        return this->passangers.size();
    } 
   
};

int main(){
    

    std::vector<Vehicle*> v;

    int range =200;
    int people = 30;
    int cap = 100;

    Person p (1,"pesho");
    CargoVehicle v1(50,1,&p,"Opel");
    CargoVehicle v2(50,1,&p,"Opel");
    PassangerVehicle pv1(50,1,&p,"cool");
    v.push_back(&v1);
    v.push_back(&v2);
    v.push_back(&pv1);

    for(int i =0 ;i<v.size();i++){
        if(v[i]->isReachable(range)){
            if(v[i]->getCargo() )
        }
    }

    return 0;
}
