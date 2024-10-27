
#include <iostream>
using namespace std;
string s;

struct Digit{
    char ch;
    int val;

};

class Number{
    
    Digit* el;

    void expand(){
        Digit* a = new Digit[size+1];
        for(int i =0 ; i < size;i++){
            a[i] = el[i];
        }
        delete [] el;
        this->el = a;
        size++;
    }
    public:
    int size;
    Number(){
        this->el = new Digit[0];
        this->size = 0;
    }

    void AddDigit(Digit d){
        expand();
        this->el[size-1]= d;
    }
    
    Digit& operator[](unsigned int i) {
        return this->el[i];
    }

};
Digit digits[255];
int digitsSize = 0;
Number num[255];
int numSize = 0;

Digit& ReturnDigit(char ch){
    for(int i =0 ;i<digitsSize;i++){
        if(digits[i].ch == ch){
            return (digits[i]);
        }
    }
}

int main(){
    cin>> s;
    for(int i =0;i<s.length();i++){
        bool isInList = false;    
        for(int j =0 ;j<digitsSize+1;j++){
            if(digits[i].ch == '=') continue;
            if(digits[j].ch == s[i]){
                isInList = true;
                //char founded
                break;
            }

        }
        if(!isInList){
            digits[digitsSize++].ch = s[i];
        }
    }

    for(int i =0 ;i <digitsSize;i++){
        if(digits[i].ch == '=') continue;
        cout << digits[i].ch << " ";
        
        cin >> digits[i].val;

    }



    for(int i =0 ;i<s.length();i++){
        if(s[i] != '\0'){
            if(s[i] == '='){
                numSize++;
                continue;
            }
            num[numSize].AddDigit(ReturnDigit(s[i]));
        }
    }

    for(int i =0; i<num[0].size;i++){
        if(num[0][i].val == num[1][i].val){
            cout << num[0][i].val;
        }
    }
    // for(int i =0; i<digitsSize; i++){
    //     cout << digits[i].ch;
    // }


    return 0;
}