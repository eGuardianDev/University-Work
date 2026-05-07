
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// void swap(ListNode* first, ListNode* second){
//     if(first == nullptr || second == nullptr) return;
//     if(first->val > second->val){
//         ListNode* temp = first->next;
//         first->next = second->next;
//         second->next = temp;
//     } 
// }


// 5, 2, 6, 1

// 2, 5, 6, 1

ListNode* insertionSortList(ListNode* head) {
    
    ListNode *curr = head; // i
    
    while(curr != nullptr){
        // cout << curr->val << endl;
        ListNode *move = curr; // j

        while(move->next != nullptr){
            if(move->val > move->next->val){
                int temp = move->val;
                move->val = move->next->val;
                move->next->val = temp;
                move = move->next; 
            }else{
                // no need to move;
                break;
            }
        }


        curr = curr->next;
    }

    return head;
}

int main(){

    ListNode * head = new ListNode(5, new ListNode(2, new ListNode(6, new ListNode(1, nullptr))));
    
    ListNode * list = insertionSortList(head);
    
    while(list != nullptr){
        cout << list->val << " ";
        list = list->next;
    }cout << endl;

    return 0;
}