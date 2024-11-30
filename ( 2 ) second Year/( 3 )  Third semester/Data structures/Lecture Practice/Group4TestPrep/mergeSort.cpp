#include <ios>
#include <iostream>

struct Node{

    int val;
    Node* next;

    Node(int val, Node* next = nullptr) : val(val), next(next){}
};


Node* getMiddle(Node* head){
    if(!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void split(Node* head, Node*& left, Node*& right){
    Node* temp = getMiddle(head);
    right = temp->next;
    left = head;
    temp->next =nullptr;
}

Node* merge(Node* first, Node* second){
    
    Node* head = new Node(0);
    Node* curr = head;

    while (first && second){
        if(first->val <= second->val){
            curr->next = new Node(first->val);
            first = first->next;
        }else{
            curr->next = new Node(second->val);
            second = second->next;            
        }
        curr = curr->next;
    }
    if(first) curr->next = first;
    else curr->next = second;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
    
    
}

void print(Node* head){
    if(head == nullptr) return;
    Node* temp = head;
    while(temp){
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

Node* sort(Node* head){
    if(!head || !head->next) return head;

    Node* left;
    Node* right;
    
    split(head,left,right);


    return merge(sort(left),sort(right));
}


int main(){

    Node* list = new Node(3, new Node(2, new Node(1,new Node(4))));

    Node* one = new Node(2,new Node(2));
    // Node* two = new Node(1,new Node(4));



    print(sort(list));
    // print(list);
    // print(getMiddle(list));

}