

using namespace std;
 
 
 
 
#include <windows.h>   // WinApi header
#include <iostream>
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
int collumsSize = 8;
int rowsSize = 8;
int arr[8][8] = {0};
int xSelected =0;
int ySelected =0;
 
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void PrintLine(char c, int size){
    for(int i =0 ;i<size; i++){
 
    cout     << c;
    }
}
 
void ShootPosition(){
    arr[ySelected][xSelected] = 1;
}
 
void display()
{ 
    for(int i =0 ;i<rowsSize ;i ++){
        PrintLine('-',(rowsSize*2+1)); cout << endl;
        for(int j =0; j < collumsSize ; j++)
        {
            cout << "|" ;
            if(xSelected == j && ySelected == i){    
              SetConsoleTextAttribute(hConsole,23);
 
            }
           cout<< arr[i][j];
 
              SetConsoleTextAttribute(hConsole,0);
        } 
        cout << "|" << endl;
            }
        PrintLine('-',rowsSize*2+1);
}
 
int main(){
 
    int c= 0;
    while(1)
    {
         c = 0; system("cls");
    display();
        switch((c=getch())) {
            case ESC:
                return 0;
            break;
            case '\r':
                ShootPosition();
            break;
        case KEY_UP:
            if(ySelected == 0 ) break;
            ySelected--;
            break;
        case KEY_DOWN:
 
            if(ySelected == 7) break;
            ySelected++;
            break;
        case KEY_LEFT:
            if(xSelected == 0  ) break;
            xSelected--;
            break;
        case KEY_RIGHT:
            if( xSelected == 7) break;
            xSelected++;
            break;
        default:
            break;
        }
        cout << "click";
    }
    return 0;
}