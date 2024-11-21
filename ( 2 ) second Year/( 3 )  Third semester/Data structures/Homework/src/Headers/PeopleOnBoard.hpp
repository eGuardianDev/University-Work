
#ifndef __PEOPLE_ON_BAORD_HPP_
#define __PEOPLE_ON_BAORD_HPP_

#include <iostream>
#include <stdexcept>
#include "addons.hpp"
#include "Board.hpp"

inline bool checkIfAroundIsPerson(Board board, int row, int collum){
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
inline int removePerson(Board &board, int row, int collum){
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

inline int SetPerson(Board& board,int row, int collum){

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


// #define _using_unsolved_algorithm
// #define _another_unsolved_algorithm_

#ifdef _using_unsolved_algorithm

inline int findPeopleInRoom(Board board, Board& outputBoard, int outputCount=0, int count = 0){
    int localRec = 9;
    for(int i =0;i<board.getRows();++i){
        for(int j =0 ;j<board.getCollums();++j){
            if(board.canPlaceOnPos(i,j)){
                ++count;
                int current= SetPerson(board, i,j);

                if(localRec > current) {
                    if(outputCount < count){
                        outputBoard = board;
                        outputCount = count;
                    }
                    localRec = current;
                    // board.PrintBoard(std::cout);
                    // std::cout <<'\n';
                    outputCount = std::max(outputCount, findPeopleInRoom(board,outputBoard,outputCount, count));
                }
                
                removePerson(board, i,j);
                --count;
            }
        }
    }
    return outputCount;
}

#endif
#ifdef _another_unsolved_algorithm_
std::vector<int> currentlyInRecursion;
inline int findPeopleInRoom(Board board, Board& outputBoard, int outputCount=0, int count = 0){
    for(int i =0;i<board.getRows();++i){
        for(int j =0 ;j<board.getCollums();++j){
            if(board.canPlaceOnPos(i,j)){
                ++count;
                int current= SetPerson(board, i,j);
                
                    int temp = (count > 1 ? currentlyInRecursion[count-2] : 0);
                    while(currentlyInRecursion.size() < count){
                        currentlyInRecursion.push_back(temp+9);
                    }

                    if(temp+current<currentlyInRecursion[count-1])
                    {
                        currentlyInRecursion[count-1] = temp +current;
                        if(outputCount < count){
                            outputBoard = board;
                            outputCount = count;
                        }
                        outputCount = std::max(outputCount, findPeopleInRoom(board,outputBoard,outputCount, count));
                    
                    }
                
                removePerson(board, i,j);
                --count;
            }
        }
    }
    return outputCount;
}

#endif
#ifndef _using_unsolved_algorithm 
#ifndef _another_unsolved_algorithm_

inline int findPeopleInRoom(Board board, Board& outputBoard, int outputCount=0, int count = 0){
    for(int i =0;i<board.getRows();++i){
        for(int j =0;j<board.getCollums();++j){
            if(board.canPlaceOnPos(i,j)){
                ++count;
                    SetPerson(board, i,j);

                    if(outputCount < count){
                        outputBoard = board;
                        outputCount = count;
                    }
                    // board.PrintBoard(std::cout);
                    // std::cout <<'\n';
                    outputCount = std::max(outputCount, findPeopleInRoom(board,outputBoard,outputCount, count));
                
                
                removePerson(board, i,j);
                --count;
            }
        }
    }
    return outputCount;
}


#endif
#endif

inline int findPeopleInRoom(Board& b){
    return findPeopleInRoom(b,b);
}

#endif