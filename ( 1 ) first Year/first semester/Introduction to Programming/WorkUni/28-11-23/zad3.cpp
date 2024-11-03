#include <iostream>
#include<iostream>
using namespace std;


void resize(int *& arr, int * size){

    int oldSize = *size;
    *size = *size * 2;

    int* arr2 = new int[*size];

    //tranfer
    for(int i = 0;i < oldSize; i ++){
      arr2[i] = arr[i];
    }
    arr = arr2;
}

int main()
{
  int size = 2;
  int* arr = new int[size];
  int index =0;
  while(true){

    string data;
    getline(cin, data);
    if (data.empty()) {
      break;
    }
    if(index >= size){
      resize(arr,&size);
    }

    int input = stoi(data);
    arr[index++] = input;

  }


  //output
  for(int i = 0;i < size; i ++){
    cout << arr[i] << ' ';
  }

  
  delete[] arr;
  return 0; 
}
