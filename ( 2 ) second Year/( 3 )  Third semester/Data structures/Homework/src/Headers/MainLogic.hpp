

#ifndef __MAIN_LOGIC_HPP_
#define __MAIN_LOGIC_HPP_



#include "Board.hpp"
#include "StudentQueue.hpp"
#include "TakingTestList.hpp"

#include <cstdint>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sys/types.h>

class MainLogic{
public:
    std::queue<uint8_t> ReadFromFileCommands(std::string path = "./input.txt");
    void LoadInputFromFile(std::string path = "./input.txt");

    bool TryLettingNextStudentIn(int time);

    short CheckForFinishingStudents(int time);

    int FindPlacesForPeople();

    const Board& getBoard() const;

    void LectureCheck(int time);

    void outputFinished(std::ostream& stream);

    // * Debug purposes
    // * Please remove The lecturer checking in main code to use use this
    // void outputToCheck(std::ostream& stream){
    //     while(!ToBeChecked.empty())
    //     {
    //         stream << (int)ToBeChecked.top()+1 << '\n'; ToBeChecked.pop();
    //     }
    // }

    //

    bool isEveryoneFinished() const;
    short EmptySeats() const ;

    
private:
    Board Room;
    short AvailableSeats;

    TakingTestList TakingTestStudents;
    
    StudentQueue studentQueue;
    std::stack<uint8_t> ToBeChecked;
    std::stack<uint8_t> Finished;

    bool checking = false;
    short lastTimePickUp = 0; //time since last pickup
    uint8_t checkingCurrently = 0; // what is the lecturer checking

    uint8_t lectureComingTime = 0;
    uint8_t lectureCheckingTime = 0;
};
#endif