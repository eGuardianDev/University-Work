#include <cassert>
#include <cctype>
#include <iostream>
#include <stdexcept>

enum Drinks{
    Beer,
    Vodka,
    Uiski,
    Tekila,
    Cola,
    Rom,
    Jhin,
    Menta,

};

struct BarSlot;

struct Client{
    std::string name;
    Drinks* wantDrinks;
    int count= 0;

    BarSlot* place;

    Client* next;
    Client* prev;
    
    Client(std::string name = "", int countOfDrinks = 0, Client* _prev = nullptr, Client* _next =nullptr ) : name(name), wantDrinks(new Drinks[countOfDrinks]), count(countOfDrinks), prev(_prev), next(_next){}
    ~Client(){
        delete [] wantDrinks;
        count = 0; // <-- is this needed?
        if(next)next->prev = nullptr; // <-- is this needed?
        if(prev)prev->next = nullptr; // <-- is this needed?
    }


    void Destruct(){
        
        if(next) {
            next->prev = nullptr;
            Client* tmp  = next;
            next = nullptr;
            tmp->Destruct();
        }
        if(prev) {
            prev->next = nullptr;
            prev->Destruct();
        }
        delete this;
    }

};
struct BarSlot{
    
    Client*  client;
    BarSlot * next;

    Drinks* drinks;
    int count =0;

    BarSlot(int n, BarSlot *_next = nullptr): drinks(new Drinks[n]), next(_next), client(nullptr), count(n){}
    ~BarSlot(){
        delete [] drinks;
        count = 0; // <-- is this needed?
        next = nullptr; // <-- same here
    }

    void Destruct(){
        //if loop is present
        BarSlot* temp = next;
        this->next = nullptr;

        if(temp)temp->Destruct();
        delete this;
    }


};

bool isSlotForClient(BarSlot * slot, Client* client){
    if(!slot || !client) return false;

    if(slot->client) return false;
    
    int i = 0, j = 0;

    while(i < client->count){
        
        if(slot->drinks[j] == client->wantDrinks[i]){
            ++i;
            j =0;
            continue;
        }
        ++j;
        if(j == slot->count) return false;
    }
    return true;
}


bool place(BarSlot * bar, Client *client){
    assert(bar && client); // <- is this better?
    // if(!bar || !client) throw std::invalid_argument("Passing null arguments");
    
    BarSlot* currSlot = bar;
    Client* currClient = client;

    int count = 5;
    while(count > 0 && currClient && currSlot){
        if(isSlotForClient(currSlot,currClient)){
            currClient->place = currSlot; // <- here
            currSlot->client = currClient;
            // currClient->place->client = currClient;
            count =5;
            currClient = currClient->next;
        }
        --count;
        currSlot = currSlot->next;
            
    }

    if(currClient || count ==0){
        // strong exception safety?
        while(currClient){
            if(currClient->place)currClient->place->client = nullptr;
            currClient = currClient->prev;
        }
        
        throw std::logic_error("Cannot place all people on the bar");   
        // return false
    
    }


    return true;
}



Drinks evaluateDrink(std::string drink){
    if(drink ==      "beer") return Beer;
    else if(drink == "vodka") return Vodka;
    else if(drink == "uiski") return Uiski;
    else if(drink == "tekila") return Tekila;
    else if(drink == "cola") return Cola;
    else if(drink == "rom") return Rom;
    else if(drink == "jhin") return Jhin;
    else if(drink == "menta") return Menta;
    
    throw std::invalid_argument("This drink doesn't exist");
}

void print(Client* client){
    if(!client) throw std::invalid_argument("printing null client");
    std::cout << client->name << " ";
}

void print(BarSlot* bar){
    if(!bar) throw std::invalid_argument("printing null bar");
    BarSlot* curr =bar;
    while(curr){
        if(curr->client) print(curr->client);
        else std::cout << "empty ";
        curr = curr->next;
    }
    std::cout << '\n';
}

bool placeAll(BarSlot *bar, Client **groups, int groupCount){
    if(!bar || !groups || groupCount <=0) return false;

    for(int i =0; i<groupCount;++i){
        try{
            place(bar, groups[i]);
        }catch(...){
            std::cout << "couldn't place group: ";
            Client* temp = groups[i];
            while(temp){
                print(temp);
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
    return true;
}

void runCLI(){
    int barCount;
    std::cout << "--generate bar--\n how many places: ";
    std::cin >> barCount;
    if(barCount <= 0) throw std::invalid_argument("cannot be 0 or negative");
    
    BarSlot* bar = new BarSlot(1);
    BarSlot* curr = bar;
    
    std::cout << "Types of drinks: beer, vodka, uiski, tekila, cola, rom, jhin, menta\n";

    for(int i =0;i<barCount;++i){
        
        std::cout << "how many drinks for place " << i+1 << ": ";
        int countOfDrinks;
        std::cin >> countOfDrinks;
        
        curr->next = new BarSlot(countOfDrinks);

        for(int j=0;j<countOfDrinks;++j){
            std::cout << "drink "<< j+1<< " type: ";
            std::string drink;
            std::cin >> drink;
            curr->drinks[i] = evaluateDrink(drink);
        }
        curr = curr->next;
    }
    
    BarSlot* temp = bar;
    bar = bar->next;
    delete temp;




    int groupsCount;
    std::cout << "how many groups of people: ";
    std::cin >> groupsCount;
    if(groupsCount <=0) throw std::invalid_argument("Groups need to be at least 1");


    Client ** Groups = new Client*[groupsCount];
    for(int i =0 ;i<groupsCount;++i){
        int currentGroupCount;
        std::cout << " how many people in group " << i+1 << ": ";
        std::cin >> currentGroupCount;
        
        Groups[i] = new Client;
        Client* curr = Groups[i];

        for(int j =0 ;j<currentGroupCount;++j){
            std::cout << "person " << j+1 << " name: ";
            std::string name;
            std::cin>> name;

            int countOfDrinksWanted = 0;
            std::cout << name << " how many drinks they like: ";
            std::cin>> countOfDrinksWanted;
            
            curr->next = new Client(name, countOfDrinksWanted);
            curr->next->prev = curr;
            curr = curr->next;
            curr->wantDrinks = new Drinks[countOfDrinksWanted];
            for(int k = 0; k<countOfDrinksWanted;++k){
                std::cout << "what type of dirnk for " << k+1 << " ";
                std::string typeOfDrink;
                std::cin >> typeOfDrink;
                curr->wantDrinks[k] = evaluateDrink(typeOfDrink);
            }
        }
        Client* temp = Groups[i];
        Groups[i]= Groups[i]->next;
        delete temp;
    }

    // print(bar);
    // for(int i =0;i<Groups)

    placeAll(bar,Groups, groupsCount);
    // for(int i=0 ;i<groupsCount;++i){
    //     print(Groups[i]);
    // }
    std::cout << "Final bar layout: \n";
    print(bar);
}

void runTests(){
    Client* f = new Client("Gosho",2);
    f->wantDrinks[0] = Beer;
    f->wantDrinks[1] = Jhin;
    Client* s = new Client("Ivans",1);
    s->wantDrinks[0] = Beer;
    
    Client* f1 = new Client("SoloDude",2);
    f1->wantDrinks[0] = Beer;
    f1->wantDrinks[1] = Jhin;

    f->next= s;
    s->prev = f;


    
    BarSlot* slot1 = new BarSlot(2);
    BarSlot* slot2 = new BarSlot(2);
    slot1->drinks[0] = Beer;
    slot1->drinks[1] = Jhin;
    
    slot2->drinks[0] = Beer;
    slot2->drinks[1] = Jhin;
    
    slot1->next = slot2;


    try{
    
        std::cout << "placing the one dude\n"; 
         place(slot1,f1);
        std::cout << "done placing\n";
    }catch(...){
        std::cout << "Error found - cannot place \n";
    }
    
    try{
    
        std::cout << "placing the duo \n"; 
         place(slot1,f);
        std::cout << "done placing\n";
    }catch(...){
        std::cout << "Error found - cannot place \n";
    }
    // std::cout << slot1->count;
    // print(f->next);
    // print(s->prev);
    print(slot1);


    // with this valgrind gives errors
    slot1->Destruct();
    // f1->Destruct();
    // f->Destruct();

    std::cout << "=============" << std::endl;
    std::cout << "Group placing" << std::endl;
    std::cout << "=============" << std::endl;


    slot1 = new BarSlot(2);
    slot2 = new BarSlot(2);
    BarSlot* slot3 = new BarSlot(2);
    slot1->drinks[0] = Beer;
    slot1->drinks[1] = Jhin;
    
    slot2->drinks[0] = Beer;
    slot2->drinks[1] = Jhin;
    
    slot3->drinks[0] = Beer;
    slot3->drinks[1] = Jhin;
    
    slot1->next = slot2;
    slot2->next = slot3;

    Client** groups = new Client*[2];
    groups[0] = f;
    groups[1] = f1;

    placeAll(slot1, groups,2);

    std::cout << "Final bar layout: ";
    print(slot1);
    
}

int main(){

    // runTests();
    runCLI();

    return 0;
}