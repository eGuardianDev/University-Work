
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode*list){
    if(list == nullptr) {std::cout << "nullptr \n";}
    while(list != nullptr){
        std::cout << list->val << ' ';
        list =list->next;
    }
    std::cout << '\n';
}



ListNode* reverse(ListNode* list){
    ListNode* newlist = nullptr;

    while(list != nullptr){
        
        ListNode* temp = list->next;   
        list->next = newlist;
        newlist = list;
        list = temp;
    }
    
    list = newlist;
    
    return newlist;
}

ListNode* RemoveFirst(ListNode* &list){
    if(list == nullptr) return nullptr;
    ListNode* temp = list;
    list = list->next;
    delete temp;
    return list;
}

bool allEmpty(vector<ListNode*>& lists){
    for(int i =0 ;i<lists.size();i++){
        if(lists[i] != nullptr) return false;
    }
    return true;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {


    ListNode* toReturn = nullptr;

    while(!allEmpty(lists)){

        ListNode *smallest = nullptr;
        int smallestIndex = -1;
        
        for(int i = 0; i < lists.size();++i){
            if(lists[i] == nullptr) continue;
            if(smallest == nullptr || smallest->val > lists[i]->val){
                smallest = lists[i];
                smallestIndex = i;
            }
        }

        if(smallest == nullptr) break;

        ListNode* temp = smallest;
        toReturn = new ListNode(smallest->val,toReturn); 

        smallest = smallest->next;
        lists[smallestIndex] = smallest;
        
        delete temp;
    }

    std::cout << "before reverse: ";
    print(toReturn);

    if(toReturn != nullptr)
        toReturn= reverse(toReturn);

    return toReturn;
}
int main(){

    vector<ListNode*> input;

    input.push_back(new ListNode(2, new ListNode(3, new ListNode(4))));
    input.push_back(new ListNode(1, new ListNode(5)));
    input.push_back(new ListNode(1, new ListNode(5)));

    print(mergeKLists(input));
    // print(input[0]);
    // print(input[1]);
    // ListNode *end = mergeKLists(input);

    return 0;
}