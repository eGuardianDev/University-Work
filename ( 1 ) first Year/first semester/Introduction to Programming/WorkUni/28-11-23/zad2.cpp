#include <iostream>
using namespace std;

int main()
{
  int size = 0;
  cin >> size;
  int** matrixRow1 = new int*[size];
  for(int i= 0;i <size; i++){
    matrixRow1[i] = new int[size];
    for(int j=0;j<size; j++){
      cin >> matrixRow1[i][j];
    }
  }
  int** matrixRow2 = new int*[size];
  for(int i= 0;i <size; i++){
    matrixRow2[i] = new int[size];
    for(int j=0;j<size; j++){
      cin >> matrixRow2[i][j];
    }
  }
  int ** matrixRowOut = new int*[size];
  for(int i =0;i <size;i++){
    matrixRowOut[i] = new int[size];
    for(int j =0 ;j<size ; j++){
      matrixRowOut[i][j]= matrixRow1[i][j] + matrixRow2[i][j];
    }
  }

  for(int i =0;i< size; i ++){
    for(int j = 0; j< size ;j ++){
      cout << matrixRowOut[i][j] << " ";
    }
    cout << endl;
  }
  for(int i =0;i < size; i++){
    delete[] matrixRow1[i], matrixRow2[i], matrixRowOut[i];
  }
  delete[] matrixRow1, matrixRow2, matrixRowOut;

  return 0; 
}
