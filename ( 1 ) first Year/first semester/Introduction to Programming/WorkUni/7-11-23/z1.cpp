#include <iostream>


void bubbleSort(char (&arr)[])
{
    for (int i = 0; i < 100; i++) {
        if(arr[i] == 0) return;
        for(int j= i;j <100 ;j ++){
            if(arr[j] == 0) break;
            if(arr[i] > arr[j]){
                char temp = arr[j];
                arr[j] = arr[i];
                arr[i]= temp;
            }
        }
    }
}
int main(){

    char str[100];
    std::cin.getline(str,100);
    bubbleSort(str);
    for(int i = 0; i< 100; i ++){
        if(str[i] == 0) break;
        std::cout << char(str[i]);

    }
    std::cout << std::endl;
    return 0;
}
