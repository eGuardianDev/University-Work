#include <iostream>
#include "addons.h"
#include "Board.h"

Board SetAroundPerson(Board board,int row, int collum){
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
                board.setOnPosition(i,j,Person);
                board = SetAroundPerson(board, i,j);
                if(globalBoardPeople < count){
                    globalBoard = board;
                    globalBoardPeople = count;
                }
                findPeopleInRoom(board, count);
                --count;
            }
        }
    }

    return count;
}

int main(){

    Board b;
    b.InitBoard(6, 7);
    b.setOnPosition(9,Broken);
    b.setOnPosition(19,Broken);
    b.setOnPosition(29,Broken);
    b.setOnPosition(4,6,Broken);

    // b = SetAroundPerson(b,0,2);
    // std::cout << b.getOnPosition(1);
    b.PrintBoard(std::cout);

    std::cout << findPeopleInRoom(b) << std::endl;
    b.PrintBoard(std::cout);
    std::cout << std::endl;

    globalBoard.PrintBoard(std::cout);

    return 0;
}