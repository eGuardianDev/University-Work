

#ifndef __BOARD_HPP_
#define __BOARD_HPP_

#include <cassert>
#include <ostream>
#include <vector>
#include "addons.hpp"

class Board{
private:

    int Board_Rows = 0;
    int Board_Collums = 0;

    std::vector<std::vector<char>> board;


public:

    const int& getRows() const{
        return Board_Rows;
    }
    const int& getCollums() const{
        return Board_Collums;
    }
    bool isInited() const{
        return Board_Rows >0;
    }
 

    Pair<short> IndexToPair(int index) const;

    void InitBoard(int rows = 8, int collums = 8);

    void PrintBoard(std::ostream& stream) const;

    void Clean();
    void Destruct();

    bool isValidPos(const int &row, const int &collum) const;

    // this is only upgrade to the default class that needs to be removed, so we want use it outside this program.
    bool canPlaceOnPos(const int &row, const int &collum) const;

    bool canPlaceOnPos(int index) const;

    bool setOnPosition(int row, int collum, const char& character);

    void setOnPosition(int index, const char &character);

    const char getOnPosition(int row, int collum) const;

    const char getOnPosition(int index) const;
};

#endif //__BOARD_HPP_