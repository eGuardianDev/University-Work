#include <iostream>
#include <new>
#include <stdexcept>

template <class T>
class Node {
public:
    T value;  // Стойност, съхранена във възела.
    Node<T>* next; // Указател към евентуалния следващ елемент.

    Node(T value = T(), Node* next = nullptr)
      : value(value), next(next)
    { }
    
    
};

template<class T>
void Delocate(Node<T> *list){
    while(list != nullptr){
        Node<T> * temp = list;
        list = list->next;
        delete temp;
    }
}
//exercise 1
template<class T>
unsigned int countOf(const Node<T>* list, const T& value){
    
    if(list == nullptr) return 0;
    //! do this with do..while

    int count = 0;
    while(list != nullptr){
        if(value == list->value){
            ++count;
        }
        list = list->next;
    }
    return count;
}  

template<class T>
unsigned int countOfRec(const Node<T>* list, const T& value){
    
    if(list == nullptr) return 0;

    // if(list->value == value){
    //     return 1 + countOf(list->next, value);
    // }else{
    //     return countOf(list->next, value);
    // }

    unsigned int counter = countOfRec(list->next,value);
    return (list->value == value ? counter : counter+1);


}   

template<class T>
void print(Node<T> *list){
    if(list == nullptr) {std::cout << "nullptr \n";}
    while(list != nullptr){
        std::cout << list->value << ' ';
        list =list->next;
    }
    std::cout << '\n';
}

//exercise 2
template<class T>
Node<T>* removeAll(Node<T>* &list, const T& value){

    // -> Version 1
    // ! not sure if it works
    // if(list == nullptr) return nullptr;

    // Node<T> *first = list;
    // while(first == list && list != nullptr){
    //     if(list->value == value){
    //         first = list->next;
    //         delete list;
    //         list = first;
    //     }else{
    //         list = list->next;
    //     }
    // }

    // -> Version 2
    // * works
    while(list != nullptr && list->value == value){
        Node<T> * temp = list;
        list = list->next;
        delete temp;
    }
    Node<T> *head = list;

    while(list->next != nullptr){
        // std::cout << list->next->value << std::endl; 
        if(list->next->value == value){
            Node<T>* temp = list->next;
            list->next = list->next->next;
            delete temp;
        }else{
            list=list->next;
        }
    }
    list = head;
    return head;
}

//ex 3
template<class T>
Node<T>* removeKth(Node<T>* list, size_t k){
    if(list == nullptr) return nullptr;
    int count =1;
    if(k ==0){
        throw std::invalid_argument("Invalid counting - cannot delete every zero element");
    }
    if(k == 1){
        Delocate(list);
        return nullptr;
    }

    Node<T> * head = list;
    while(list->next != nullptr){
        ++count;
        if(count == k){
            Node<T>* temp = list->next;
            list->next = list->next->next;
            delete temp;
            count = 0;
        }
        else list=list->next;
        
    }
    return head;
}

//ex 4
template<class T>
Node<T>* reverse(Node<T>* list){
    Node<T>* newlist = nullptr;

    while(list != nullptr){
        
        Node<T>* temp = list->next;   
        list->next = newlist;
        newlist = list;
        list = temp;
    }
    
    list = newlist;
    
    return newlist;
}

template<class T>
Node<T>* cloneReversed(Node<T>* first){

    Node<T>* curr = first;
    Node<T>* toReturnAllocated = nullptr;

    while(curr != nullptr ){
        try{
            Node<T>* temp = new Node<T>(curr->value, toReturnAllocated);
            toReturnAllocated = temp;
            curr = curr->next;
        } catch( ... ){
            if(toReturnAllocated != nullptr){
                Delocate(toReturnAllocated);
            }
            throw std::bad_alloc();
        }
    }


    return toReturnAllocated;

}

int main(){

    Node<int>* list = new Node<int>(1, new Node<int>(2,new Node<int>(1,new Node<int>(2,new Node<int>(4,new Node<int>(3,nullptr))))));
    // std::cout << "1: " <<countOf(list,1) << "\n";
    // std::cout << "2: " <<countOf(list,2) << "\n";

    print(list);
    // Node<int> * temp = cloneReversed(list);
    removeAll(list, 1);
    print(list);
    // print(temp);

    Delocate(list);
    //Delocate(temp);
    return 0;
}