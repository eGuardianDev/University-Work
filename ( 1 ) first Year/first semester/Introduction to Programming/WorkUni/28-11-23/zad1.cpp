#include <iostream>
using namespace std;

int main()
{
  int size =0;
  cin >> size;

  int* arr = new int[size];

  for(int i =0; i < size ; i++){
    cin >> arr[i];
  } 

  for(int i =0; i < size ; i++){
    cout <<arr[i]; 
  } 
  delete[] arr;

  cout << " end; "<< endl;
  return 0; 
}
