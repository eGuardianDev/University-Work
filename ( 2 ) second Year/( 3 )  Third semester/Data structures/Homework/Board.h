
#include <cassert>
#include <ostream>
#include <stdexcept>
#include <vector>
#include "addons.h"


class Board{
private:

    int Board_Rows = 8;
    int Board_Collums = 8;

    std::vector<std::vector<char>> board;


public:

    const int& getRows() const{
        return Board_Rows;
    }
    const int& getCollums() const{
        return Board_Collums;
    }
 

    Pair<int> IndexToPair(int index) const{
        int row = 0;
        int collum = 0;
        while(index >=Board_Collums){
            row++;
            index -= Board_Collums;
        }
        collum = index;
        return Pair<int>(row,collum);
    }


    void InitBoard(int rows = 8, int collums = 8){
        if(board.size() > 0) throw std::overflow_error("Board already initialized");

        if(rows <=0 || collums <=0) throw std::invalid_argument("Cannot initialize empty or negative size board");

        Board_Rows = rows;
        Board_Collums = collums;

        for(int i =0 ;i<rows; ++i){
            board.push_back(std::vector<char>());
        }

        for(int i =0; i< board.size(); i++){
            for(int j =0; j<collums; ++j){
                board[i].push_back(valid);
            }      
        }
    }

    void PrintBoard(std::ostream& stream) const{
        if(board.size() == 0) throw std::underflow_error("Printing empty board");
        for(std::vector<char> row : board){
            for(int i =0 ;i <row.size();++i){
                stream << row[i] << " ";
            }
            stream << std::endl;
        }
    }

    bool isValidPos(const int &row, const int &collum) const{
        return (row >=0 && row <Board_Rows &&
                collum >=0 && collum <Board_Collums); 
    }



    // this is only upgrade to the default class that needs to be removed, so we want use it outside this program.
    bool canPlaceOnPos(const int &row, const int &collum) const {
        if(!isValidPos(row, collum)) return false;
        
        char toTest = board[row][collum];
        return toTest == valid;
    }

    bool canPlaceOnPos(int index)const {
        Pair<int> temp = IndexToPair(index);
        return canPlaceOnPos(temp.first, temp.second);
    }


    bool setOnPosition(int row, int collum, const char& character) {
        assert(isValidPos(row,collum));
        board[row][collum] = character;
        return true;
    }

    void setOnPosition(int index, const char &character){
        Pair<int> temp = IndexToPair(index);
        setOnPosition(temp.first,temp.second,character);
    }

    const char getOnPosition(int row, int collum) const{
        assert(isValidPos(row, collum));
        return board[row][collum];
    }

    const char getOnPosition(int index) const{
        Pair<int> temp = IndexToPair(index);
        return getOnPosition(temp.first,temp.second);
    }
};

