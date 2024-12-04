
#ifndef _Tree_
#define _Tree_

struct T_Node{
    int val;
    T_Node* left;
    T_Node* right;

    T_Node(int _val, T_Node* _left = nullptr, T_Node* _right = nullptr)
    : val(_val), left(_left),right(_right){ }

    ~T_Node(){}
    void Destruct(){
        if(left) left->Destruct();
        if(right) right->Destruct();
        delete this;
    }
};


#endif