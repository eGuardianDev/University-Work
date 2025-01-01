
#include "../Headers/TakingTestList.hpp"
#include <utility>
TakingTestList::TakingTestList(){
    head = nullptr;
    size = 0;
}

TakingTestList::~TakingTestList(){
    clear();
    size = 0;
}
TakingTestList::TakingTestList(const TakingTestList& other){
    copy(other.head);
    this->size = other.size;
}

TakingTestList& TakingTestList::operator=(const TakingTestList& other){
    if(this != &other){
        clear();
        this->size = other. size;
        copy(other.head);
    }
    return *this;
}

TakingTestList::TakingTestList(TakingTestList&& other){
    swap(*this, other);
}
TakingTestList& TakingTestList::operator=(TakingTestList&& other){
    if(this != &other){
        clear();
        swap(*this, other);
    }

    return *this;
}

const int TakingTestList::Size() const {
    return size;
}


void TakingTestList::copy(Node* other){
    assert(other);
    if(other == nullptr) return;
    
    
    Node* current = new Node(other->student);
    Node* otherPointer = other;
    otherPointer = otherPointer->next;
    head = current;
    
    while(otherPointer){
        current->next = new Node(otherPointer->student);
        current = current->next;
        otherPointer = otherPointer->next;
    }
}

bool TakingTestList::Inbetween(Student student, Node* current)const {
    if(current->next == nullptr){
        return false;
    }
    int nodeTime = current->student.getTimeComing() + current->student.getTimeNeeded();
    int studentTime = student.getTimeComing() + student.getTimeNeeded();

    int nextNodeTime = current->next->student.getTimeComing() +current->next->student.getTimeNeeded();
    
    return (nodeTime <= studentTime) && (studentTime < nextNodeTime);
}

void TakingTestList::push(Student student){
    if(head == nullptr){
        head = new Node(student);
        ++size;
        return;
    }

    Node* curr = head;

    int studentTime = student.getTimeComing() + student.getTimeNeeded();
    
    if(curr->student.getTimeComing()+
        curr->student.getTimeNeeded() > studentTime){
        Node* temp = new Node(student);
        temp->next = head;
        head = temp;
        ++size;
        return;
    }

    while(curr->next != nullptr){     
        if(Inbetween(student, curr)){
            Node* temp = curr->next;
            curr->next = new Node(student);
            curr->next->next = temp; 
            ++size;
            return;
        }
        curr = curr->next; 
    }

    curr->next = new Node(student);
    ++size;
    
}
Student& TakingTestList::front(){
    return head->student;
}
void TakingTestList::pop(){
    Node* temp = head;
    head = head->next;
    delete temp;
    --size;
}
bool TakingTestList::empty() const{
    return head == nullptr && size == 0;
}

void TakingTestList::clear(){
    Node* temp;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}


void swap(TakingTestList& first, TakingTestList& second){
    std::swap(first.head, second.head);
    std::swap(first.size, second.size);
}
