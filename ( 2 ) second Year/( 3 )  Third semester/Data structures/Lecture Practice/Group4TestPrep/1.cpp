#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* doubleIt(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* toReturn = nullptr;

    while(curr != nullptr){
        curr->val *= 2;
        if(curr->val > 9){
            curr->val -= 10;
            if(prev){
                prev->val +=1;
            }else{
                prev = new ListNode(1,curr);
                toReturn =prev;
            }
        }
        prev = curr;
        curr = curr->next;
        if(!toReturn) toReturn = prev;
    }

    return toReturn;
}

int main(){
    ListNode* data = new ListNode(9,new ListNode(2));

    ListNode* temp = doubleIt(data);

    while(temp){
        std::cout << temp->val;
        temp = temp->next;
    }
    std::cout << '\n';

    return 0;
}