#include "Init.h"
#include "../Printing/Menus.h"
#include "../Game/Game.h"
#include <iostream>
#include <fstream>
#include <string>   
#include <curses.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#define Up_key 65
#define Left_key 68
#define Down_key 66
#define Right_key 67
#define Esc_key 27
#define Enter_key 13
#define Space_key 32
#define X_key 120
#define Z_key 122


char CheckForInput(){
        system("stty raw");
        char c = getchar(); 
        system("stty cooked");
       // system("clear");
        switch(c){
            case '.':
             system("stty cooked");
             exit(0);
            break;
            case Up_key:
            system("stty cooked");
            UpKeyPressed();
            break;
            case Down_key:
            system("stty cooked");
            DownKeyPressed();
            break;
            case Left_key:
            system("stty cooked");
            LeftKeyPressed();
            break;
            case Right_key:
            system("stty cooked");
            RightKeyPressed();
            break;
            case Enter_key:
            system("stty cooked");
            EnterKeyPressed ();
            break;

        }
        if(c == '.') {
            system("stty cooked");
            exit(0);
        }  
    return c;
}

void UpKeyPressed(){
    if(Menu == MainM)
    {
        SelectUpMainMenu();
     //   MoveSelectedUp();
    }else if(Menu==GameM){

        SelectUP();
    }
}

void DownKeyPressed(){
    if(Menu == MainM)
    {   
        SelectDownMainMenu();
      //  MoveSelectedDown(); 
    }else if(Menu == GameM){
        SelectDOWN();
    } 
}



void LeftKeyPressed(){
    if(Menu == GameM){
    SelectLEFT();   
    }
}

void RightKeyPressed(){
    if(Menu == GameM){
    SelectRIGHT();
    }
}

void EnterKeyPressed(){
    if(Menu == MainM){
        SelectedDoFunction();
    }else if(Menu == GameM){
        
        DoGameAction();
    }
}