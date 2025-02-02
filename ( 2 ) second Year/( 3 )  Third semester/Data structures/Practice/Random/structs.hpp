#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>
struct Client;
enum Drinks{
        beer,
        vodka,
        uiski,
        tekila,
        cola,
        rom,
        jhin,
        menta
    };
struct BarSlot{
    Drinks* drinks = nullptr;
    int drinkCount =0;
    BarSlot* next = nullptr;
    Client* client = nullptr;

    BarSlot(Drinks* drinks,int count) : drinks(drinks), drinkCount(count) {}
    ~BarSlot(){delete drinks;}
    void Destruct(){
        if(next) next->Destruct();
        delete this;
    }

};


struct Client{
    std::string name ="";
    Drinks* drinks=nullptr;
    Client* next= nullptr;
    Client* prev= nullptr;

    BarSlot* bar = nullptr;

    int drinkCount = 0;
    Client(std::string name, Drinks* drinks,int count) :name(name), drinks(drinks), drinkCount(count){}
    ~Client(){
        delete [] drinks;
    }
    void Destruct(){
        if(next) next->Destruct();
        delete this;
    }
};
class Bar{
    public:
    

    #define maxGap 5



    int count(BarSlot* slot){
        if(slot == nullptr) return 0;
        return 1 + count(slot->next);
    }
    int count(Client* slot){
        if(slot == nullptr) return 0;
        return 1 + count(slot->next);
    }
    int countEmptySeats(BarSlot* slot){
        if(slot == nullptr) return 0;
        if(slot->client == nullptr) return 1 + count(slot->next);
        return count(slot->next);
    }


    bool machingDrinks(BarSlot* bar, Client* client){
        if(! bar || ! client) throw std::logic_error("empty bar or client");
        if(bar->drinks < client->drinks) return false;

        for(int i =0;i<client->drinkCount;++i){
            bool flag = false;
            for(int j=0;j<bar->drinkCount;++j){
                if(client->drinks[i] == bar->drinks[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }


    void print(BarSlot* bar){
        int index = 1;
        while(bar){
            if(bar->client){
                std::cout << "Bar " << index << ":" << bar->client->name << std::endl;
            }
            index++;
            bar = bar->next;
        }
    }
    bool placing(BarSlot* bar, Client* client, int count =0){
        if(count > maxGap) return false;
        if(!bar && client) return false;
        if(bar && !client) return true;
        if(!bar && !client) return true;

        if(bar->client == nullptr){
            if(machingDrinks(bar,client)){
                bar->client = client;
                client->bar = bar;
                if(placing(bar->next, client->next)==false){
                    client->bar= nullptr;
                    bar->client = nullptr;
                    return false;
                }else{
                    return true;
                }
            }else{
                if(placing(bar->next, client,count +1)==false){
                    client->bar= nullptr;
                    bar->client = nullptr;
                    return false;
                }else{
                    return true;
                }
            }
        }else{
                if(placing(bar->next, client,count +1)==false){
                    client->bar= nullptr;
                    bar->client = nullptr;
                    return false;
                }else{
                    return true;
                }
            }
        return false;
    }

    bool place(BarSlot* bars, Client* clients){
        int barCount = countEmptySeats(bars);
        int clientCount = count(clients);
        if(clientCount > barCount) return false;
        // return true;
        return placing(bars,clients);
    }
};