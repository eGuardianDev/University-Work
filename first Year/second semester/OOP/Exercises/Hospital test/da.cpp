#include <iostream>

template<typename T>
int map(T a[], int n, T(*f)(T a)){

    for(int i = 0 ;i <n;i ++){
        a[i] = f(a[i]);
    }
    return 0;
}

int main(){

    int a[] = {1,2,3};

    map<int>(a,3, [](int x)->int{return x+1;});


    for(int i = 0; i< 3 ;i++){
        std::cout << a[i] << "\n"; 
    }


    return 0;
}