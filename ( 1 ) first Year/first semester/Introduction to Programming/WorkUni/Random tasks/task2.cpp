#include <iostream>
using namespace std;


bool isPrime(int a){
    if(a <= 1) return 0;
    for(int i = 2; i <a;i++){
        if(a%i == 0){
            return 0;
        }
    }
    return 1;
}

int checkCountOfDevisible(int n){
    int count = 0;
    for(int k = 2; k < n; k++){
        if(n%k == 0){
            count++;
        }         
    }
    return count;
}
int main(){

    int a,b;
    cin >> a >>b;

    for(int n = a;n <=b;n++){
        // taking number in [a,b]

        bool flag = 1;
        int count = checkCountOfDevisible(n);
        if(!isPrime(count)) {flag = 0;}

        if(flag && count > 0){
            cout << n << endl;
        }


    }

    return 0;
}