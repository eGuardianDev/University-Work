#include <iostream>
using namespace std;

int main()
{
  //plan matrix with strings
  //display stirng intill new line

  string str = "";
  getline(cin,str);
  char ** arr = new char*[64];
  int index =0;

  arr[index] = new char[64];
  int tempindex =0;
  for(int i = 0;i < str.length(); i++){
    
    if(str[i] != ' '){
      arr[index][tempindex] = str[i];
      tempindex++;
    }else{
      tempindex = 0;
      index++;
      arr[index] = new char[64];
      
    }

  }
  
  for(int i = 0; i<=index; i++){
    for(int j =i +1 ; j<=index;j++){
     if((arr[i][0]) > ((int)arr[j][0])){
       
        char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        

      }
    }
  }

  tempindex = 0;
  for(int i =0; i<=index; i++){
    for(int j =0; j<sizeof(arr[index]);j++){
      cout << arr[i][j];
    }
    cout <<endl;
  }

  cout << index + 1 << " Words";
 
  return 0; 
}