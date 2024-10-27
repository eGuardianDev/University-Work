#include <iostream>
using namespace std;

int getMax(long a,long b ,long c){
    return (a>b && a>c) * 0 + (b>c && b >a )* 1 + (c>a && c > b) * 2;
}

unsigned long countSums(unsigned long *a,unsigned long *b,unsigned long *c,int n ){
    int count = 0;

    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            for(int k = 0;k <n;k++){
                if( (a[i] == (b[j] + c[k])) || ( b[j] ==(a[i] + c[k])) || (c[k] == (a[i] + b[j]))){
                    count++;
                }
            }
        }
    }

    return count;
}

int main(){
    int n;
    cin >> n;
    unsigned long arrays[3][n];

    for(int i = 0;i <3;i++){
        for(int j =0;j<n ;j++){
            cin >>arrays[i][j];
        }
    }

    long count = countSums(arrays[0],arrays[1], arrays[2],n);
    cout << count;

    // for(int i =0; i < 3; i++){
    //     delete[] arrays;
    // } // това ми дава много грешки и не знам как да го оправя
}