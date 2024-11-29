

#include <iostream>
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val =0, Node* prev=nullptr,Node* next =nullptr) : val(val),next(next),prev(prev){} 
    ~Node(){
        if(next) next->prev = prev;
        if(prev) prev->next = next;
        prev = next = nullptr;
    }
    void print(){
        std::cout << val << " ";
        if(next) next->print();
    }
};

int findTheWinner(Node* head,int k){
    int count = 1;

    while(head->next != head && head->prev != head ){
        if(count == k) {
            Node* toDelete = head; 
            head =head->next;
            delete toDelete;
            count = 1;
            continue;
        }
        head = head->next;
        ++count;
    }

    return head->val;
}


Node* reverse(Node * head){

    if(head == nullptr) return nullptr;

    Node* curr = head;
    Node* next;
    Node* prev;

    while(curr != nullptr){
        next = curr->next;
        // prev = curr->prev; // mine

        // curr->next = prev; // mine
        curr->next = curr->prev;
        curr->prev = next; 

        prev = curr; // not mine
        curr = next;
    }

    // return prev->prev; // mine
    return prev;
}


int findTheWinner(int n, int k) {
    Node* curr = new Node(1);
    Node* start = curr;
    for(int i =2;i<=n;++i){
        curr->next = new Node(i,curr,nullptr);
        curr =curr->next;
    
    }
    curr->next = start;
    start->prev = curr;



    // start->print();
    return findTheWinner(start,k);
}

int main(){

    Node* f1 = new Node(1);
    Node* f2 = new Node(2);
    Node* f3 = new Node(3);

    f1->next = f2;
    f2->next = f3; f2->prev = f1;
    f3->prev = f2;
    

    f1->print(); std::cout<<std::endl;
    reverse(f1)->print();

    // std::cout << findTheWinner(5,2); // 3
    // std::cout << findTheWinner(6,5); // 1
    return 0;
}