#include <iostream>
#include <iterator>


class interpreter{
    class Node;
    public:
    interpreter() { head = nullptr;}
    ~interpreter(){
       if(head) head->Clear();
        head = nullptr;
    }

    void whole(){
        Node* curr = head;
        while(curr->prev){
            curr = curr->prev;
        }
        while(curr){
            std::cout << curr->val;
            curr = curr->next;
        }
    }

    void expand(int count){
        if(count <=0) return;
        Node * temp;
        
        if(!head){
            temp = new Node();
            head = temp;
            for(int i =1;i<count;++i){
                temp->next = new Node();
                temp->next->prev = temp;
                temp = temp->next;
            }
        }else{
            head->next->prev = nullptr;
            head->next->Clear();

            temp = head;
            for(int i =0;i<count;++i){
                temp->next = new Node();
                temp->next->prev = temp;
                temp = temp->next;
            }
        }
        size+=count;
    }

    std::size_t getSize(){ return size;}
    bool empty() {return size == 0;}
    char operator*(){
        return head->val;
    }
    interpreter* operator+=(int count){
        head->val+=count;
        return this;
    } 
  
    interpreter* operator-=(int count){
        head->val-=count;
        return this;
    }
    interpreter* operator++(){
        if(head->next)head =head->next;
        return this;
    }
    interpreter* operator++(int){
        ++(*this);
        return this;
    }
    interpreter* operator--(){
        if(head->prev)head =head->prev;
        return this;
    }
    interpreter* operator--(int){
        ++(*this);
        return this;
    }


    class Iterator{
        public:
        Iterator(Node* i){
            a = i;
        }
        char operator*(){
            return a->val;
        }
        bool endPoint(){
        return (a->next == nullptr); 
        }
        Iterator* operator++(){
            a=a->next;
            return this;
        }
        Iterator* operator++(int){
            Iterator* toRet = this;
            ++(*this);
            return toRet;
        }
        Iterator* operator--(){
            a=a->prev;
            return this;
        }
        Iterator* operator--(int){
            Iterator* toRet = this;
            --(*this);
            return toRet; 
        }
        bool operator==(Iterator other){
            return this->a == other.a;
        }  bool operator!=(Iterator other){
            return this->a != other.a;
        }  bool operator<(Iterator other){
            return this < &other;
        } 
        private:
        Node* a;
    };

    Iterator begin(){
        Node* curr= head;
        while(curr->prev){
            curr = curr->prev;
        }
        return curr;
    } 
    Iterator end(){
        
        return nullptr;
    } 

    private:
    

    std::size_t size = 0;

    struct Node{
        char val = 'a';
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(char val = 'a', Node* prev = nullptr, Node* next = nullptr):
        val(val), prev(prev), next(next){}
        ~Node(){}
        int Clear(){
            int i =0;
            
            if(next){
                next->prev = nullptr;
                i+=next->Clear();
            } 
        
            if(prev) {
                prev->next = nullptr;
                i+=prev->Clear();
            }
            delete this;
            return i+=1;
        }
    } *head;


};



void Interpre(char* a){
    interpreter in;
    char *b = a;
    int count =0;
    while(*b != '\0')
    {
        ++count;
        ++b;
    }
    in.expand(count);
    // std::cout << in.getSize();
   
    while(*a != '\0'){
        if(*a== '>'){
            in++;
        }
        else if(*a== '<'){
            in--;
        }
        else if(*a =='+'){
            in+=1;
        }
        else if(*a =='-'){
            in-=1;
        }
        ++a;
    }


    for(auto i = in.begin();i != in.end(); ++i){
        std::cout << *i << " ";
    }
    // std::cout << *in.end();


}

int main(){
    
    Interpre(">+");
    return 0;
}