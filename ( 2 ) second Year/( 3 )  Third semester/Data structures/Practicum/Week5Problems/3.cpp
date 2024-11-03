#include <bitset>
#include <iostream>
#include <queue>


void PopSpecific(std::queue<char> &queue, char &toRemove){
    int size = queue.size();
    std::queue<int> tempHolder;

    for(int  i=0;i < size;++i){
        char ch = queue.front();
        queue.pop();
        if(ch == toRemove){
            break;
        }
        tempHolder.push(ch);
    }

    int k = tempHolder.size();


    //get temp put at back
    for(int i =0;i< k;++i){
        queue.push((tempHolder.front()));
        tempHolder.pop();
    }

    //get front put at back to fix sorting
    for(int i =0;i< size-k;++i){
        queue.push((queue.front()));
        queue.pop();
    }
}

int main(){

    std::queue<char> elements;
    std::bitset<26> chars;
    char a;
    while( a != '0') {
        std::cin >> a;
        if(elements.size() > 0 && chars[int(a-60)] == true){
            PopSpecific(elements,a);
            std::cout << "-1 ";
        }else if(chars[int(a-60)] == false){
            chars[int(a-60)] = true;
            elements.push(a);
        }
        else{
            std::cout << elements.front() << ' ';
            elements.push(a);
        }
    }


    return 0;
}