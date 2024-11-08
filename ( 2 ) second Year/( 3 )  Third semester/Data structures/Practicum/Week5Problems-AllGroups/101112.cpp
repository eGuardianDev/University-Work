#include <iostream>
#include <vector>
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
void print(Node<T> *list){
    if(list == nullptr) {std::cout << "nullptr \n";}
    while(list != nullptr){
        std::cout << list->value << ' ';
        list =list->next;
    }
    std::cout << '\n';
}

template<class T>
unsigned int count(Node<T>* &list)
{
    Node<T> *curr = list;
    int count =0;
    while(curr != nullptr){
        curr = curr->next;
        ++count;
    }
    return count;
}


//ex 10
template<class T>
Node<T>* GetMiddle(Node<T> * first){
    Node<T>* result = first;
    int counted = count(first);
    counted = counted/2;
    while(counted){
        result = result->next;
        
        --counted;
    }

    return result;
}


template <class T>
bool contains(std::vector<T> list, T element){
    for(T el : list){
        if(el == element){
            return 1;
        }
    }
    return 0;

}
//ex 11
template<class T>
bool hasCycle(Node<T>* first){
    Node<T>* checking = first;
    std::vector<Node<T>*> visited;
    while(checking){
        if(contains(visited, checking))
        {
            return 1;    
        }
        visited.push_back(checking);
        checking = checking->next;
    }
    return 0;
}

template<class T>
Node<T>* getNStepsAhead(Node<T>* head, unsigned int n){
    while(n > 0){
        head= head->next;
        --n;
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
bool isPalindrom(Node<T>* first){
    Node<T>* curr = first;
    Node<T>* rev = reverse(first);
    Node<T>* stop = GetMiddle(first);
    while(curr){
        if(curr == stop) return 1; // optimization i guess ???
        if(curr->value != rev->value){
            return 0;
        }
        curr = curr->next;
        rev = rev->next;
    }
    return 1;
    
}


int main(){


    // print(first);
    // print(temp);



    // Node<int> *first = new Node<int>(1, new Node<int>(2));
    // Node<int> *temp = new Node(3, new Node<int>(4, first->next));
    // first->next->next = temp;
    
    // std::cout << hasCycle(first);

    Node<int> *first = new Node<int>(1, new Node<int>   (2, new Node<int>(0)));
    // std::cout << isPalindrom(first);
    print(first);
    getNStepsAhead(first,2);
    print(first);



    return 0;
}