#include <iostream>

using namespace std;

int main()
{

   //x axis (length)
   int a,l;
   int b,l1;
   int lenght;
   
   //y axis (heigth)
   int ya,h;
   int yb,h1;
   int height;
   
   cin >>a>>ya>>l>>h >>b>>yb>>l1>>h1;
   if(l1 < 0){
        b += l1;
        l1 = -l1;
   }
   if(l < 0){
       a += l;
       l = -l;
   }
   if(b>a){
       lenght = a+l-b;
       if(lenght <=0){
           //no way
       }else{
           if(lenght > l1){
               lenght = l1 ;
           }
       }
   }else if ( a>b){
      lenght = b+l1-a;
       if(lenght <=0){
           //no way
       }else{
           if(lenght > l ){
               lenght = l ;
           }
       } 
   }else{
       if(l > l1)lenght = l1;
       else if (l <= l1) lenght = l;
   }
//   cout << lenght;
    if(lenght <= 0){
        cout << "Not overlaping" << endl;
        cout << 0 << endl;
        return 1;
    }

   
    if(h1 < 0){
        yb += h1;
        h1 = -h1;
   }
   if(h < 0){
       ya += h;
       h = -h;
   }
   if(yb>ya){
       height = ya+h-yb;
       if(height <=0){
           //no way
       }else{
           if(height > h1){
               height = h1 ;
           }
       }
   }else if ( ya>yb){
      height = yb+h1-ya;
       if(height <=0){
           //no way
       }else{
           if(height > h ){
               height = h ;
           }
       } 
   }else{
       if(h > h1)height = h1;
       else if (h <= h1) height =h;
   }
   //cout << height<<endl;
    if(height){
        cout << "Not overlaping" << endl;
        cout << 0 << endl;
        return 1;
    }

   cout << "Area : " <<height * lenght << endl;
   
   
    return 0;
}

