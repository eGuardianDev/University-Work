
#include <iostream>
#include <cmath>
using namespace std;

void splitNumber(int arr[], int n){
    int index =0;
    while(n!=0){
        arr[index++] = n % 10;
        n /=10;
    }
}
void generateNumber(int arr[]){
    int n = rand() % 10000 +1;
    splitNumber(arr,n);
    for(int i=0;i<4;i++){
        for(int j = 0; j<4;j++){
            if(i ==j) continue;
            if(arr[i] == arr[j]){
                if(arr[j]==9){
                    arr[i] = 0;
                    j = 0;
                }else{
                  arr[j]++;
                }
            }
        }    
    }
}
int Cows(int arr[],int arr2[]){
    int count = 0;
    for(int i = 0;i<4;i ++){
        for(int j =0;j <4;j++){
                if(i ==j) continue;
            if(arr[i] == arr2[j]){
                count++;
            }
        }
    }
    return count;
}
int Bulls(int arr[], int arr2[]){
    int count=0;
    for(int i =0;i <4;i++){
        if(arr[i] == arr2[i]){
            count++;
        }
    }
    return count;
}
int main()
{
    srand(int (time(0)));
    int secretArr[4];
    int inputs[4];
    generateNumber(secretArr);
    
    int n;
    int br;
    while(true){
        cin >> n;
        splitNumber(inputs, n);
        bool flag = true;
        br++;
        for(int i =0;i <4;i++){
            if(inputs[i] != secretArr[i]){
                flag = false;
                break;
            }
        }
        if(flag == true) break;
        cout << "Крави :" << Cows(secretArr, inputs) << " Бикове :" << Bulls(secretArr,inputs) << endl;
        //cout << secretArr[3]<<secretArr[2]<<secretArr[1]<<secretArr[0];
               
    }
    cout <<"you won with" << br<<" tries." <<endl;
    return 0;   
}