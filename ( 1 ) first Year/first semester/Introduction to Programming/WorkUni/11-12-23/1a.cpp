#include <iostream>

using namespace std;



int A[7][8] = { 
{1,1,4,3,6,13,11,2},
{2,2,5,14,3,1,1,1},
{2,2,8,4,10,16,12,4},
{2,2,2,1,5,4,3,6},
{2,2,1,5,2,9,14,13},
{2,2,3,4,5,6,7,8},
{2,2,7,8,9,14,15,16}};

void displayMatrix(){
    for(int i =0 ;i<7;i++){

    for(int j =0 ;j<8;j++){
      cout << A[i][j];
    }

  }
}

void checkForSameRowsSums(){
  for(int i = 0;i < 7;i++){
    int *row1 = A[i];
    
    for(int j= i+1;j < 7 ;j ++){
        int * row2 = A[j];
        int sum1 = 0;
        int sum2 = 0;;
        for(int t = 0; t<8; t++){
          sum1 += row1[t];
          sum2 += row2[t];
        }
        if(sum1 == sum2){
          cout << "rows with numbers " << i << " and " << j <<" have the same sum";
        }

    }
  }


}

void checkForSameCollumSums(){
  int sums[8] = {0};
  for(int i =0 ;i<8;i++){
    for(int j =0;j<7;j++){
      sums[i]+=A[j][i] ; 
    }
  }

  for(int i = 0;i<8;i++){
    for(int j =i+1;j<8; j++){
      if(sums[i] == sums[j]) cout << "found matching sums at " << i << " and " << j << endl;
    }
  }
}

void checkForBiggerLines(){

  for (int i = 0;i<7;i++){
    for(int j = i+1; j<7;j++){
      bool flag =true;
      for(int t = 0;t <8; t++){
        if(A[i][t] > A[j][t]){
          flag = false; break;
        }
      }
      if(flag == true){
        cout << "Row " << i << " <  " << j << "\n";
      }
    }
  }

}

void Even(){
  for(int i =0; i<7;i++){
    bool flag = true;
    for(int j = 0;j <8;j++){
      if(A[i][j] % 2 !=0){
        flag =false;
        break;
      }
    }
    if(flag == true) cout << i<<" Row is even";
  }
}

void Sorted(){

  for(int i =0;i<7;i++){
    bool flag =true;
    for (int j =1;j<8;j++){
      if(A[i][j-1]> A[i][j])
      {
        flag = false; break;
      }
    }
    if(flag == true) cout << i << " Row is sorted";
  }
}

void horizontalMove(){
  int movement = 1;
    int index =0;
  for(int i =0 ;i<7;i++){
    
    if(i%2 ==0){

      for(int j = 0; j< 8; j++){
        cout <<A[i][j] << " ";
      }
      
    }else{
      for(int j = 7;j>0; j--){
        cout << A[i][j] << " ";
      }
    }
    cout << endl;
  }
}
void verticalMove(){
  
  for(int c = 0; c < 8; c++){
    if(c %2==0){
      for(int r = 0 ;r<7;r++){
        cout<< A[r][c] << " ";
      }
    }else{
      for(int r = 7;r>0;r--){
        cout << A[r][c] << " ";
      }
    }
    cout << endl;
  }
  

}
int main()
{

  //checkForSameRowsSums();
 // checkForSameCollumSums();
  //checkForBiggerLines();
  //horizontalMove();
  //verticalMove();
  
  return 0; 
}
