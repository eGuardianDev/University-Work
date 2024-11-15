#include <iostream>
#include <stdexcept>
#include "addons.h"
#include "Board.h"

bool checkIfAroundIsPerson(Board board, int row, int collum){
    for(int i =-1;i<2;++i){
        for(int j =-1 ;j<2;++j){
            int newR = row + i;
            int newC = collum+ j;
            if(board.isValidPos(newR,newC)){
                if(board.getOnPosition(newR,newC) == Person){
                    return true;
                }
            }
        }
    }
    return false;
}
int removePerson(Board &board, int row, int collum){
    if(!board.isValidPos(row, collum)) {
        throw std::invalid_argument("Trying to remove person out of board");
    }
    if(board.getOnPosition(row,collum) != Person) {
        throw std::invalid_argument("Selected Item is not a person");
    }
    int removed=0;
    board.setOnPosition(row,collum,valid);
    for(int i =-1;i<2;++i){
        for(int j =-1 ;j<2;++j){
            int newR = row + i;
            int newC = collum+ j;

            if(j == 0 && i ==0) continue;

            if(board.isValidPos(newR,newC) && 
            board.getOnPosition(newR,newC) == invalid &&
            !checkIfAroundIsPerson(board, newR, newC)){
                board.setOnPosition(newR,newC,valid);
                ++removed;
            }
            
        }
    }
    return removed;
}

int SetPerson(Board& board,int row, int collum){

    assert(board.isValidPos(row, collum));
    int placed = 0;
    board.setOnPosition(row,collum,Person);
    for(int i =-1;i<2;++i){
        for(int j =-1 ;j<2;++j){
            int newR = row + i;
            int newC = collum+ j;
            if(j == 0 && i ==0) continue;
            if(board.canPlaceOnPos(newR,newC)){
                board.setOnPosition(row+i,collum+j,invalid);
                ++placed;
            }
        }
    }
    return placed;
}

Board globalBoard;
int globalBoardPeople = 0;
int a = 0;
int findPeopleInRoom(Board board, int count = 0){
    int minTaken =9;
    for(int i =0;i<board.getRows();++i){
        for(int j =0 ;j<board.getCollums();++j){
            if(board.canPlaceOnPos(i,j)){
                ++count;
                int current= SetPerson(board, i,j);
                if(current < minTaken){
                    if(globalBoardPeople < count){
                        globalBoard = board;
                        globalBoardPeople = count;
                        std::cout << "saving on this -> ";
                    }
                    std::cout<< "Step: " << count << "\n";
                    board.PrintBoard(std::cout);
                    // std::cout << "\n\r" << ++a;
                    minTaken = current;
                  
                    findPeopleInRoom(board, count);
                }
                removePerson(board, i,j);
                --count;
            }
        }
    }

    return count;
}

int main(){

    Board b;
    b.InitBoard(6,7);

    b.setOnPosition(9,Broken);
    b.setOnPosition(19,Broken);
    b.setOnPosition(29,Broken);
    
    // std::cout << b.getOnPosition(9);
    // system("clear");

    findPeopleInRoom(b);
    // SetPerson(b,5,0);
    // removePerson(b,5,0);
    //!!!can remove at left down


    // b.PrintBoard(std::cout);
    globalBoard.PrintBoard(std::cout);



    return 0;
}