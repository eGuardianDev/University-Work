#include "Game.h" 

bool isBuildingState = false;

int GameBoard[sizeOfBoard][sizeOfBoard] = {0};
int EnemyBoatBoard[sizeOfBoard][sizeOfBoard] = {0};
int AllyBoatBoard[sizeOfBoard][sizeOfBoard] = {0};


// selection
int selectedRow = 0;
int selectedCollum = 0;


//Building phase
void SpawnBoat(int row, int collum);
void RotateBoat(int r);

void GenerateRandomPositions(int array[sizeOfBoard][sizeOfBoard]);

void SelectUP(){
    if(selectedRow >0){
        selectedRow--;
    }
}
void SelectDOWN(){

    if(selectedRow <sizeOfBoard-1){
        selectedRow++;
    }
}
void SelectLEFT(){
    
    if(selectedCollum > 0){
        selectedCollum--;
    }
}
void SelectRIGHT(){

    if(selectedCollum <sizeOfBoard-1){
        selectedCollum++;
    }
}


//attack phase
void AttackOn(int row, int collum);
void DisplayAllyBoard(){
    for(int i =0 ;i < sizeOfBoard; i++){
        std::cout << "| ";
        for( int j =0; j<sizeOfBoard; j++){
            bool flag =false;
            if(selectedRow == i && selectedCollum == j){
                flag = true;
            }
            switch( AllyBoatBoard[i][j]){

                case -2:
                if(flag){std::cout <<"\033[92m";}
                std::cout << 'X' << "\033[97m | ";
                break;
                default:
                if(flag)std::cout << "\033[92m";
                else std::cout <<"\033[97m";
                std::cout << AllyBoatBoard[i][j] << "\033[97m | ";
                break;
            }
        }
        std::cout << std::endl;
    }
}

void GenerateRandomNumber();

void DoGameAction(){
    if(!isBuildingState){
        if(EnemyBoatBoard[selectedRow][selectedCollum] != 0 ){
            return;
        }
        if(EnemyBoatBoard[selectedRow][selectedCollum] == 1 ){
            EnemyBoatBoard[selectedRow][selectedCollum] = -1;
            AllyBoatBoard[selectedRow][selectedCollum] = -1;
            return;
        }
        EnemyBoatBoard[selectedRow][selectedCollum] = -2;
        AllyBoatBoard[selectedRow][selectedCollum] = -2;

    }
}

//main loop
void GamePlay(){

    if(!isBuildingState){
        DisplayAllyBoard();
        return;
    } 
}

