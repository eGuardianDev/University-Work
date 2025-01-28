#include <ios>
#include <iostream>
#include <ostream>



template<class T>
class LinkedList{
    template<class V>
    struct Node;
public:
    LinkedList(){}
    ~LinkedList(){clean();}

    void clean(){
        if(head) head->Destruct();
        size = 0;
    }
    void appendBack(T element){
        Node<T> *curr = head;
        if(!curr){
            head = new Node<T>(element);
            tail =head;
        }else{
            tail->next = new Node<T>(element);
            tail = tail->next;
        }
        ++size;
    }
   
  
    bool remove(std::size_t index){
        return remove(index,head);
    }

    std::ostream& print(std::ostream& strm){
        Node<T> *curr = head;

        while(curr && curr->next){
            strm << curr->val<<", ";
            curr = curr->next;
        }
        if(curr){
            strm << curr->val;
            strm << std::endl;
        }

        return strm;
    }

    bool member(T elem){
        Node<T>* curr = head;

        while(curr){
            if(curr->val == elem) return true;
            curr = curr->next;
        }
        return false;
    }
    const std::size_t Size() const{
        return size;
    }


    class Iterator{
        public:
        Iterator(Node<T>* node) { pointer = node;}
        ~Iterator(){}

        Iterator operator++(){
            if(pointer){
                pointer = pointer->next;
            }
            return *this;
        }
        Iterator operator++(int){
            Iterator res = *this;
            if(pointer){
                pointer = pointer->next;
            }
            return this;
        }

        Node<T> operator*(){
            return *pointer;
        }
        Node<T>* operator->(){
            return pointer;
        }

        bool operator==(Iterator other)const{
            return pointer == other.pointer;
        }
        bool operator!=(Iterator other) const{
            return pointer != other.pointer;
        }

        private:
            Node<T>* pointer = nullptr;
    };

    Iterator begin() { return Iterator(head);}
    Iterator end() { return Iterator(nullptr);}

private:
    bool remove(std::size_t index, Node<T>* &curr ){
        if(index ==0 && curr){
            Node<T> *toDelete = curr;
            curr = curr->next;
            delete toDelete;
            size--;
            return true;
        }else if(index > 0 && curr && curr->next){
            return remove(index-1, curr->next);
        }
        return false;
    }

private:
    std::size_t size =0;
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    template<class V>
    struct Node{
        V val;
        Node *next = nullptr;
        Node(V value) : val(value){
        }
        void Destruct(){
            if(next)next->Destruct();
            delete this;
        }
    };
};

int main(){

    LinkedList<int> list;
    list.appendBack(3);
    list.appendBack(5);

    list.print(std::cout);
    list.print(std::cout);

    return 0;
}