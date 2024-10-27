#include <iostream>


class BasicCar{

    private:
    int yearOfProduction;
    std::string model;

    public:
    std::string getModel(){
        return model;
    }
    int getYearOfProduction(){
        return yearOfProduction;
    }
    BasicCar(int y, std::string m){
        this->yearOfProduction = y;
        this->model = m;
        std::cout << "Created basic car" << std::endl;
    }
    ~BasicCar(){
        std::cout << "Deleted basic car" << std::endl;
    }
    const void print(){
        std::cout << "Model: " <<model << " year of production: " << yearOfProduction <<std::endl;
    }

    virtual bool isDrivable(double distance){
        return false;
    }
    virtual int range(){
        return 0;
    }
};

class ElectricCar : public BasicCar{
    private:
    //kwatts
    double battery_cap;
    double battery_charge;
    double usagePer100Km;
    public:
    ElectricCar(double battery_cap, double battery_charge, double usagePer100Km, int y, std::string m) : BasicCar(y,m) {
        this->battery_charge = battery_charge;
        this->battery_cap = battery_cap;
        this->usagePer100Km = usagePer100Km;
    }
    ~ElectricCar() { std::cout << "Electric car deleted" << std::endl;}
    bool isDrivable(double distance) {
        double range = battery_charge / usagePer100Km * 100;
        if(range >= distance){
            return true;
        }
        return false;
    }
    int range(){
        double range = battery_charge / usagePer100Km * 100;
        return range;
    }
    const void print(){
        std::cout <<
        "Model: " << this->getModel() <<
        " Year: " << this->getYearOfProduction() <<
        " Battery capacity : " << this->battery_cap <<
        " Battery charge: " << this->battery_charge <<
        " Range: " << this->range() << std::endl;
    }

};
class CombustionCar : public BasicCar{
    private:
    //kwatts
    double Tank;
    double fuel;
    double usagePer100Km;

    public:
    CombustionCar(double Tank, double fuel, double usagePer100Km, int y, std::string m) : BasicCar(y,m) {
        this->fuel = fuel;
        this->Tank = Tank;
        this->usagePer100Km = usagePer100Km;
    }
    ~CombustionCar() { std::cout << "Electric car deleted" << std::endl;}
    bool isDrivable(double distance) {
        double range = fuel / usagePer100Km * 100;
        if(range >= distance){
            return true;
        }
        return false;
    }
    int range(){
        double range = fuel / usagePer100Km * 100;
        return range;
    }
    const void print(){
        std::cout <<
        "Model: " << this->getModel() <<
        " Year: " << this->getYearOfProduction() <<
        " Tank Capacity : " << this->Tank <<
        " Fuel: " << this->fuel <<
        " Range: " << this->range() << std::endl;
    }

};

class HybridCar : public CombustionCar, public ElectricCar{

    public:
    CombustionCar(double Tank, double fuel, double usagePer100Km, int y, std::string m) : CombustionCar(y,m) ElectricCar{
     
    }
 
};


int main(){
    ElectricCar eCar(10,5,3,2024, "Asus");
    ElectricCar cCar(20,3,3,2008, "stupidCar");
    eCar.print();
    cCar.print();
    return 0;
}