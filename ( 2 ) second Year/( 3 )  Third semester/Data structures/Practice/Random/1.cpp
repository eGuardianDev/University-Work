#include <iostream>

#include "structs.hpp"


int main(){


    Bar bar;

    Drinks drinks[] = {vodka, beer};
    Drinks drinks2[] = {vodka};
    Drinks drinks3[] = {beer};
    BarSlot* slot = new BarSlot{drinks, 2};
    BarSlot* slot2 = new BarSlot{drinks, 2};
    BarSlot* slot3 = new BarSlot{drinks, 2};
    Client* client = new Client{"gosho",drinks2,1};
    Client* client2 = new Client{"pesho",drinks3,1};
    slot->next = slot2;
    slot2->next = slot3;
    Client* client3 = new Client{"misho",drinks3,1};
    Client* client4 = new Client{"risho",drinks3,1};

    client3->next = client4;
    client4->prev = client3;
    client->next = client2;
    client2->prev = client;
    std::cout << bar.place(slot,client) << std::endl;
    bar.print(slot);

    std::cout << bar.place(slot,client3) << std::endl;
    bar.print(slot);

    return 0;
}