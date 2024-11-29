#include <cstdlib>
#include <iostream>
#include <valarray>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool allEmpty(std::vector<ListNode*>& lists){
    for(ListNode* a : lists){
        if(a != nullptr) return false;
    }
    return true;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;

    ListNode* toReturn = new ListNode(0);
    ListNode* curr = toReturn;

    ListNode* currentMin;
    int index = 0;

    while(!allEmpty(lists)){
        currentMin = lists[0];
        index =0;
        for(int i =1;i<lists.size();++i){
        
            if(lists[i]&&( !currentMin || currentMin->val > lists[i]->val)){
                currentMin = lists[i];
                index = i;
            }
        }
        curr->next = new ListNode(currentMin->val);

        curr = curr->next;
        ListNode* temp = lists[index];
        lists[index] = lists[index]->next;
        delete temp;

    }

    ListNode* temp = toReturn;
    toReturn = toReturn->next;
    delete temp;


    return toReturn;
}


void print(ListNode* node){
    while(node != nullptr){
        std::cout << node->val << " ";
        node = node->next;   
    }
}

int main(){

    std::vector<ListNode*> vector;
    vector.push_back(new ListNode(1, new ListNode(2, new ListNode(3))));
    vector.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    vector.push_back(new ListNode(1, new ListNode(2, new ListNode(4))));
    
    ListNode* res = mergeKLists(vector);
    print(res);

    while(res){
        ListNode* temp = res;
        res= res->next;
        delete temp;
    }



    return 0;
}