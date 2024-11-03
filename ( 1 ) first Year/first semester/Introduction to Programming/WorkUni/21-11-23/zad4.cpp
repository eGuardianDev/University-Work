#include <iostream>
using namespace std;

int stirngLenght(char* str){
  int k = 0;
  for(int i = 0;i<64;i++){
      if(str[i] == 0)break;
      k++;

  }

return k;
}

int main()
{
  char str[64];
  cin.getline(str, 64);
  cout << stirngLenght(str);

  return 0; 
}
#include <iostream>
using namespace std;

int main()
{


  return 0; 
}
