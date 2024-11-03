
#include <iostream>
#include "../Common/Common.h"
#include "../Game/Game.h"
#include "Menus.h"
#include <fstream>
#include <string>   
#include <curses.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "MenuFunctions.h"
MenuOptions Menu;
#include <ncurses.h>
struct winsize size;
std::string LogofileName = "Logo";
std::string Logo;

int collumsOfTerminal;
int rowsOfTerminal;

struct SelectableButton{
    std::string Text;
    bool Selected;
    void(*func)();
};

struct MenuType{
    public:
        std::string Name;
        SelectableButton * selectableButtons;
};

void StartGameFunc(){
    std::cout << "Starting game";
    Menu = GameM;
}
void _Exit(){
    std::cout << "\aExtiing";
    exit(0);
}
void Restart(){
    std::cout << "\aRestaring";
    exit(0);
}

SelectableButton selectableButtonMainMenu[]= {
    {"Start", true, StartGameFunc},
    {"Exit", false, _Exit},
    {"Exit 2 ", false, Restart}
};
MenuType MainMenus = {
    "Main Menu",
    selectableButtonMainMenu
};
void SelectUpMainMenu(){
    for(int i =0 ;i < int(sizeof(selectableButtonMainMenu)/sizeof(SelectableButton));i++){
        if(i != 0 && selectableButtonMainMenu[i].Selected == true){
            selectableButtonMainMenu[i].Selected = false;
            selectableButtonMainMenu[i-1].Selected = true;
            return;
        }
    }
}
void SelectDownMainMenu(){
     int count = (int)sizeof(selectableButtonMainMenu)/sizeof(SelectableButton);
     for(int i =0 ;i < count ; i++){ 
        if(i != count-1 && selectableButtonMainMenu[i].Selected == true){
            selectableButtonMainMenu[i].Selected = false;
            selectableButtonMainMenu[i+1].Selected = true;
            return;
        }
    }

}
void SelectedDoFunction(){
     int count = (int)sizeof(selectableButtonMainMenu)/sizeof(SelectableButton);

     for(int i =0 ;i < count ; i++){ 
        if(selectableButtonMainMenu[i].Selected == true){
            selectableButtonMainMenu[i].func();
            return;
        }
    }
}

void InitMenu(){
    //get terminal size (not dynamic sadly)
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    // 
    Logo = GetLogo("Logo.txt");
}
void PrintSelectableButtons( SelectableButton selectableButtons[],int NumberOfElements, std::string selectableColor = "\033[1;31m"){
  //int count =(int)sizeof(selectableButtons)/sizeof(SelectableButton);
    for(int i = 0; i < NumberOfElements;i++){
        SelectableButton s = selectableButtons[i];
        int lenght = s.Text.length();
        if(s.Selected){
            std::cout << selectableColor; // color red
        }
        PrintBox(s.Text,(size.ws_col-lenght)/2);
        std::cout << "\033[0m\n"; // reset color
    }
}
void CallMainMenu(){

    //printing logo
    // std::string logo = GetLogo("Logo.txt");
        PrintChars(' ',(size.ws_col - 83)/2);
    for(int i= 0; i < (int)Logo.length(); i++){
        std::cout << Logo[i];
        if((int)Logo[i] == 10 && i+1 !=(int)Logo.length()){
            PrintChars(' ',(size.ws_col - 83)/2);
        }
    }
    //printing select buttons/boxes
    // std::cout << "Buttons:\n";
    PrintSelectableButtons(selectableButtonMainMenu, sizeof(selectableButtonMainMenu)/sizeof(SelectableButton));
 
}

