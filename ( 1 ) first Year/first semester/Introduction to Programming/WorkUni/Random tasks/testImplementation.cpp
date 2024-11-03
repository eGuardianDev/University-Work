/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    
    int arr[4];
    arr[0] = 9;
    arr[1] = 9;
    arr[2] = 0;
    arr[3] = 1;
    
    for(int i=0;i<4;i++){
        for(int j = 0; j<4;j++){
            if(i ==j) continue;
            if(arr[i] == arr[j]){
                if(arr[j]==9){
                secretArr }else{
                  arr[j]++;
                }
            }
        }    
    }
    cout<<arr[3]<<arr[2]<<arr[1]<<arr[0];

    return 0;
}
