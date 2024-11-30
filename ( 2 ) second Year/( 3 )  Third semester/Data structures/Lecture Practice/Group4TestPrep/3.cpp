#include <algorithm>
class MinStack {

struct Node{
    int minVal;
    int val;
    Node *next;
    Node(int val, int _minVal, Node* next = nullptr) 
    : val(val), minVal(_minVal), next(next) { }
};

Node *tos;
public:
    MinStack() {
    tos = nullptr;       
    }
    
    void push(int val) {
        if(!tos) tos = new Node(val, val);
        else{
            int min = std::min(tos->minVal, val);
            tos = new Node(val, min, tos);
        }
    }
    
    void pop() {
        Node* temp = tos;
        tos = tos->next;
        delete temp;
    }
    
    int top() {
        return tos->val;
    }
    
    int getMin() {
        return tos->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */