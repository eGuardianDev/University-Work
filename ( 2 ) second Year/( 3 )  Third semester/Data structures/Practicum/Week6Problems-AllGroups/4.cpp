#include <iostream>
using namespace std;



class BrowserHistory {
    struct Node {
    public:
        Node(string val) : val(val){
            prev= nullptr;
            next = nullptr;
        }
        string val;
        Node* prev;
        Node* next;
        ~Node(){
            if(prev != nullptr){
                delete prev;
            }
            if(next != nullptr){
                delete next;    
            }
        }
    };
    Node *history;
public:
    BrowserHistory(string homepage) {
        history = new Node(homepage);
    }
    void visit(string url) {
        if(history->next != nullptr){
            Node * temp = history->next;
          
            while(temp != nullptr){
                Node* t = temp->next;
                temp->prev = nullptr;    
                temp->next = nullptr;
                delete temp;
                temp = t;
            }
        }
        history->next = new Node(url);
        history->next->prev = history;
        history = history->next;
        
    }
    
    string back(int steps) {
        while(steps > 0 && history->prev != nullptr){
            --steps;
            history = history->prev;
        }
        return history->val;
    }
    
    string forward(int steps) {
        while(steps >0 && history->next != nullptr){
            --steps;
            history = history->next;
        }
        return history->val;
    }
};

int main(){
    /*
["BrowserHistory","visit","visit","back","visit","forward","visit","visit","forward","visit","back","visit","visit","forward"]
[["esgriv.com"],["cgrt.com"],["tip.com"],[9],["kttzxgh.com"],[7],["crqje.com"],["iybch.com"],[5],["uun.com"],[10],["hci.com"],["whula.com"],[10]]
    */
    BrowserHistory bh("esgriv.com");
    bh.visit("cgrt.com");
    bh.visit("tip.com");
    bh.back(9);
    bh.visit("kttzxgh.com");
    bh.forward(7);
    bh.visit("crqje.com");
    bh.visit("iybch.com");
    bh.forward(5);
    bh.visit("uun.com");
    std::cout << bh.back(10);
    bh.visit("hci.com");
    // bh.visit("whula.com");
    // bh.forward(10);
    return 0;
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */