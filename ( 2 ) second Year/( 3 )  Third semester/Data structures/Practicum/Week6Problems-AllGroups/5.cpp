#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;

class TextEditor {
    struct Node {
    public:
        Node(char val) : val(val){
            prev= nullptr;
            next = nullptr;
        }
        char val;
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

    Node *textEdit;
public:
    TextEditor() {
        textEdit = nullptr;
    }

    void printNode(Node* selected){
        Node* current = selected;
        while(current != nullptr){
            std::cout << current->val;
            current = current->next;
        }
    } 
    void printNode(Node* selected, string& output){
        Node* current = selected;
        while(current != nullptr){
            output+= current->val;
            current = current->next;
        }
    }
    void printALL(){
        if(textEdit == nullptr) 
            throw underflow_error("trying to print empty text");
        Node* curr = textEdit;
        while(curr->prev != nullptr){
            curr = curr->prev;
        }
        printNode(curr);
        
    }
    
    void addText(string text) {
        if(text == "") return;

        if(textEdit == nullptr){
            textEdit = new Node(text[0]);
            for(int i =1 ;i<text.size();++i){
                textEdit->next = new Node(text[i]);
                textEdit->next->prev = textEdit;
                textEdit = textEdit->next;
            }
            return;
        }

        for(int i =0;i<text.size();++i){
            if(!textEdit->next){
                textEdit->next = new Node(text[i]);
                textEdit->next->prev = textEdit;
            }else{
                textEdit->next->val = text[i];
            }
            textEdit = textEdit->next;
        }

    }
    
    int deleteText(int k) {
        int count = 0;
        while(k >0 && textEdit){
            ++count;
            --k;

            Node* next = textEdit->next;
            Node* toDelete = textEdit;

            textEdit = textEdit->prev;
            
            if(textEdit) textEdit->next = next;
            if(next) next->prev = textEdit;
            toDelete->next = toDelete->prev = nullptr;
            delete toDelete;
        }
        return count;
    }
    
    int countToTheLeftEnd(){
        Node* temp = textEdit;
        int count =0;
        while(temp->prev){
            ++count;
            temp = temp->prev;
        }
        return count;
    }
    string leftFromCursor(){
        int n = min(10,countToTheLeftEnd());
        // int n = 2;
        int temp = n;
        string data;
        Node* node = textEdit;
        while(temp >1 && node->prev){
            node = node->prev;           
            --temp;
        }
        while(n >0){
            data += node->val;
            node = node->next;
            --n;
        }
        return data;

    }
    string cursorLeft(int k) {
        int count= k;
        while(k > 0 && textEdit->prev){
                --k;
                textEdit = textEdit->prev;
        }
        // cout << textEdit->val;
        return leftFromCursor();
        return "";
    }
    
    string cursorRight(int k) {
       int count= k;
        while(k > 0 && textEdit->next){
                --k;
                textEdit = textEdit->next;
        }
        // cout << textEdit->val;
        return leftFromCursor();
        return "";
    }
};

int main(){
    TextEditor te;

    te.addText("leetcode");
    std::cout << te.deleteText(4);
    te.addText("practice");
    std::cout <<te.cursorRight(3);
    te.addText("leet");
    cout << te.cursorLeft(4);
    // cout<< te.cursorRight(10);
    // te.printALL();

    return 0;
}
