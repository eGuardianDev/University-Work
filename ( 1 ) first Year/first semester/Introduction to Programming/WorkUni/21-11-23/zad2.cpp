#include <iostream>

using namespace std;
void increment (int& num){
    num+=1;
}
int main()
{
  int a;
  cin >> a;
  increment(a);
  cout << a;
  return 0; 
}
