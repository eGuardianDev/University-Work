// game settings

// board

#include <iostream>
const int sizeOfBoard = 8;


//Building phase
void SpawnBoat(int row, int collum);
void RotateBoat(int r);

void GenerateRandomPositions(int array[sizeOfBoard][sizeOfBoard]);

//attack phase
void AttackOn(int row, int collum);
void DisplayAllyBoard();

void GenerateRandomNumber();

void SelectUP();
void SelectDOWN();
void SelectLEFT();
void SelectRIGHT();


void DoGameAction();

//main loop
void GamePlay();

