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
Board removePerson(Board board, int row, int collum){
    if(!board.isValidPos(row, collum)) {
        throw std::invalid_argument("Trying to remove person out of board");
    }
    if(board.getOnPosition(row,collum) != Person) {
        throw std::invalid_argument("Selected Item is not a person");
    }
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
            }

            
        }
    }
    return board;
}

Board SetPerson(Board board,int row, int collum){
    assert(board.isValidPos(row, collum));
    board.setOnPosition(row,collum,Person);
    for(int i =-1;i<2;++i){
        for(int j =-1 ;j<2;++j){
            int newR = row + i;
            int newC = collum+ j;
            if(j == 0 && i ==0) continue;
            if(board.canPlaceOnPos(newR,newC)){
                board.setOnPosition(row+i,collum+j,invalid);
            }
        }
    }
    return board;
}

Board globalBoard;
int globalBoardPeople = 0;

int findPeopleInRoom(Board board, int count = 0){
    for(int i =0;i<board.getRows();++i){
        for(int j =0 ;j<board.getCollums();++j){
            if(board.canPlaceOnPos(i,j)){
                ++count;
                board = SetPerson(board, i,j);
                if(globalBoardPeople < count){
                    globalBoard = board;
                    globalBoardPeople = count;
                }
                findPeopleInRoom(board, count);
                board = removePerson(board, i,j);
                --count;
            }
        }
    }

    return count;
}

int main(){

    Board b;
    b.InitBoard(6,7);
    // b.setOnPosition(1,Broken);
    // b.setOnPosition(3,Broken);
    // b.setOnPosition(5,Broken);
    // b.setOnPosition(10,Broken);
    b.setOnPosition(9,Broken);
    b.setOnPosition(19,Broken);
    b.setOnPosition(29,Broken);

    findPeopleInRoom(b);


    b.PrintBoard(std::cout);
    globalBoard.PrintBoard(std::cout);

    // std::cout << findPeopleInRoom(b) << std::endl;


    // globalBoard = removePerson(globalBoard,0,0);
    // globalBoard = removePerson(globalBoard,2,0);
    // globalBoard = removePerson(globalBoard,0,2);
    // globalBoard = removePerson(globalBoard,2,2);
    // globalBoard.PrisntBoard(std::cout);

    return 0;
}