/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int Optimization(int a, int l, int b, int l1){
    if(l1 < 0){
            b += l1;
            l1 = -l1;
    } 
     if(l < 0){
       a += l;
       l = -l;
    }
    int lenght = 0;
    
    if(b>a){
        lenght = a+l-b;
        if(lenght >0){
           if(lenght > l1){
               lenght = l1 ;
           }
        }
     } if ( a>b){
        lenght = b+l1-a;
        if(lenght >0){
           if(lenght > l ){
               lenght = l ;
           }
        } 
     }else{
       lenght = (int(l>l1) * l1) + (int(l<l1) * l);
     }
    return int(lenght>0)* lenght;
}

int main()
{
   int a,l;
   int b,l1;
   int lenght;

   int ya,h;
   int yb,h1;
   int height;
   
   cin >>a>>ya>>l>>h >>b>>yb>>l1>>h1;
   lenght = Optimization(a,l,b,l1);
   height = Optimization(ya,h,yb,h1);
  
   cout << "Area : " <<height * lenght << endl;
   
    return 0;
}