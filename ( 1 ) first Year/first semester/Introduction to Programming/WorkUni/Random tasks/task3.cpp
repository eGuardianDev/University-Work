#include <iostream>

using namespace std;

float pow(float  n, float x){
    if(x == 0) return 1;
    float ret = n;
    for(int i = 1;i<x;i++){
        ret*=n;
    }
    return ret;
}
float factorial(float n){
    if( n == 1) return n;
    return n * factorial(n-1);
}

int main(){

    float n,x;
    cin >> n;
    cin >> x;
    float sum = 0;
    for(int i = 0;i<=n;i++){
        sum += pow(-1,n)*( pow(x,((2*i)+1)) / factorial((2*i)+1) );
    }
    cout << sum;
    return 0;
}