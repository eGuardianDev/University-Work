#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void print(ListNode *list){
    ListNode* temp = list;
    if(list == nullptr) {std::cout << "nullptr \n";}
    while(temp != nullptr){
        std::cout << temp->val << ' ';
        temp =temp->next;
    }
    std::cout << '\n';
}

ListNode* reverse(ListNode* list){
    ListNode* newlist = nullptr;
    ListNode* curr = list;

    while(curr != nullptr){
        newlist = new ListNode(curr->val,newlist);
        curr = curr->next;
    }
    
    curr = newlist;
    
    return newlist;
}

int countList(ListNode* head){
    int count = 0;
    ListNode *curr = head;
    while(curr != nullptr){
        ++count;
        curr = curr->next;
    }
    return count;
}

ListNode* Swap(ListNode* list, ListNode* next){
    if(list == nullptr) return nullptr;
    ListNode* temp = list->next;
    list->next = next;
    return list;
}

ListNode* Next(ListNode* curr, ListNode* change){
    ListNode* temp = curr->next;
    curr->next = change;
    return temp;
}


void deloc(ListNode* list){
    ListNode* curr = list->next; 
    while(curr != nullptr){
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    list = nullptr;
}

// void reorderList(ListNode* head){

//     ListNode* front = head;
//     ListNode* back = reverse(head);
    
//     // ListNode* toReturn = nullptr; // when copying

//     bool flag = false;

//     int count = countList(head);
//     ListNode* prev;
//     while(count > 0){
//         ListNode* curr = nullptr;
//         ListNode* other = nullptr;
//         if(flag == false) 
//         {
//             curr = front;
//             other =back;
//         }
//         else {
//             curr = back;
//             other = front;
//         }
//         // toReturn = new ListNode(curr->val, toReturn); //when copying
//         // if(flag == false) front = front->next;
//         // else back = back->next;

//         if(flag == false){
//             front = Next(curr, other);
//         }else{
//             back = Next(curr, other);
//         }
//         prev = curr;
//         flag = !flag;
//         --count;
//     }


//     prev->next = nullptr;
//     // ! this here is problem
//     // ! memory leak is found here because some elements exist but are not used?
//     // ! run dealocator
//     // print(nano);

    
// }

void reorderList(ListNode* head){
    int count =countList(head);
    ListNode** list = new ListNode*[count];
    ListNode *cur = head;

    for(int i =0;i<count;++i){
        list[i] = cur;
        cur = cur->next;
    }

  
    while(count > 1){
        

    }


    delete [] list;
}

int main(){

    ListNode *first = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(10))));


    print(first);
    reorderList(first);
    print(first);

    return 0;
}