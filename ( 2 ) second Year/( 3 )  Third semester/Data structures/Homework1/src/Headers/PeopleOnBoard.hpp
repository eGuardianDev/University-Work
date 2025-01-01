
#ifndef __PEOPLE_ON_BAORD_HPP_
#define __PEOPLE_ON_BAORD_HPP_

#include "Board.hpp"

bool checkIfAroundIsPerson(Board board, int row, int collum);

int removePerson(Board &board, int row, int collum);

int setPerson(Board& board,int row, int collum);

int findPeopleInRoom(Board board, Board& outputBoard, int outputCount=0, int count = 0);

int findPeopleInRoom(Board& b);

#endif