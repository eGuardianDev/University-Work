#include <iostream>


int main(){


    int *a = new int(1); // one parameter
    int *arr = new int[3]; // Static array
    // ^ saved in heap, needs "delete [] arr"  
    // ==
    int staticArr[3]; // saved in stack

    int n =3;
    int *dynamicArr = new int[n];
    // dynaic array
    // when input data isn't known..
    // still needs "delete [] dynamicArr"


    int statickArray2d[3][3]; // 2d staitc array 3x3
  
    int **dynamicArray2d = new int*[3]; // 2d  array array 3x3
    //  ^^ pointer to pointer
    
    // int **********************mental; // crazy type of shit

    for(int i =0;i<3;++i){
        dynamicArray2d[i] = new int[3];
    }




    delete a;
    delete [] arr; // pointer
   // delete staticArr // error, because not a pointer
    delete [] dynamicArr; 

    //only pointers use delete

    //deleting 2d array
    //delete every element
    for(int i =0; i<3;++i){
        delete [] dynamicArray2d[i];
    }
    //delete holder
    delete [] dynamicArray2d;


    return 0;
}