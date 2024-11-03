
#include "main.h"

bool dev =true;
bool gameStarted = false;
int StartGame(){
     GamePlay();
    return 0;
}


int main(){
    
      while(1){
        std::cout << "Start\n";
        InitMenu();
        std::cout << "Calling main\n";
        switch(Menu){
            case MainM:
            CallMainMenu();
            break;
            case GameM:
            StartGame();
            
            break;
        }
        
        
        CheckForInput();
    }
    return 0;
}