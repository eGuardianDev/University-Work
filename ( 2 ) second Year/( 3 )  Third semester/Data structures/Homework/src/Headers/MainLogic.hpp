

#ifndef __MAIN_LOGIC_HPP_
#define __MAIN_LOGIC_HPP_



#include "Board.hpp"
#include "PeopleOnBoard.hpp"
#include "Student.hpp"
#include "StudentQueue.hpp"
#include "TakingTestList.hpp"

#include <cstdint>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <sys/types.h>

class MainLogic{
public:
    std::queue<uint8_t> ReadFromFileCommands(std::string path = "./input.txt"){


        std::ifstream File;

        File.open(path);

        if(!File.is_open())
        {
            throw std::invalid_argument("File \"input.txt\" doesn't exist");
        }
        
        std::queue<uint8_t> commands;
        std::string data;
        while(File >> data)
        {
            if(data == "enter") continue;
            if(data == "end") break;
            commands.push(stoi(data));
        }

        File.close();

        
        return commands;
    }

    void LoadInputFromFile(std::string path = "./input.txt"){

        std::queue<uint8_t> cmd = ReadFromFileCommands(path);

        int n = cmd.front();
        cmd.pop();
        int m = cmd.front();
        cmd.pop();

        Room.InitBoard(n,m);
            // lector's times
        lectureComingTime = cmd.front();
        cmd.pop(); 
        lectureCheckingTime = cmd.front();
        cmd.pop();


        int BrokenChairs = cmd.front();
        cmd.pop();

        for(int i =0;i<BrokenChairs;++i){
            int indexOfBroken = cmd.front();
            cmd.pop();

            Room.setOnPosition(indexOfBroken, Broken);
        }


        while(!cmd.empty())
        {
            int timeComing = cmd.front(); cmd.pop();
            int id = cmd.front()-1; cmd.pop();
            int timeNeeded = cmd.front(); cmd.pop();
            int course = cmd.front(); cmd.pop();

      
            studentQueue.push(Student(timeComing,id,timeNeeded,course));   
        }
    }

  

    bool TryLettingNextStudentIn(int time){
        assert(Room.isInited());
        assert(AvailableSeats > 0);

        if(TakingTestStudents.Size() == AvailableSeats) return false;

        if(studentQueue.isEmpty()) return false;

        Student curr = studentQueue.front(time);
        if(time < curr.TimeComing) return false;

      

        curr.TimeComing = time;
        TakingTestStudents.push(curr);
        studentQueue.pop(time);

        return true;

    }

    short CheckForFinishingStudents(int time){

        assert(Room.isInited());
        assert(AvailableSeats > 0);

        if(TakingTestStudents.empty()) return 0;
        int count =0; //students exiting the room
        
        Student curr = TakingTestStudents.top();
        while(!TakingTestStudents.empty()){

            curr = TakingTestStudents.top();

            if(curr.getTimeComing() + curr.getTimeNeeded()>time) return count;

            TakingTestStudents.pop();
            ToBeChecked.push(curr.Id);
            ++count;

       
        }
        return count;
    }


    const int FindPlacesForPeople(){
        assert(Room.isInited());
        AvailableSeats = findPeopleInRoom(Room);
        return AvailableSeats;
    }

    const Board getBoard() const {
        return Room;
    }

bool checking = false;

    void LectureCheck(int time){
        if(time < lectureComingTime) return;

        if(checking){
            if(lastTimePickUp+lectureCheckingTime ==time){
                checking = false;
                Finished.push(checkingCurrently);
            }
        }


        if(!checking &&!ToBeChecked.empty())
        {   
            checking = true;
            checkingCurrently = ToBeChecked.top();

            ToBeChecked.pop();
            lastTimePickUp = time;
        }

        return;
    }

    void outputFinished(std::ostream& stream){
        while(!Finished.empty())
        {
            stream << (int)Finished.top()+1 << '\n'; Finished.pop();
        }
    }

    // * Debug purposes
    // * Please remove The lecturer checking in main code 
    // void outputToCheck(std::ostream& stream){
    //     while(!ToBeChecked.empty())
    //     {
    //         stream << (int)ToBeChecked.top()+1 << '\n'; ToBeChecked.pop();
    //     }
    // }

    //

    bool isEveryoneFinished(){
        return ToBeChecked.empty() && checking==false && TakingTestStudents.empty() && studentQueue.isEmpty(); 
    }

    short EmptySeats(){
        return AvailableSeats - TakingTestStudents.Size();
    }

    
// private:
    Board Room;
    short AvailableSeats;
    

    // std::priority_queue<Student,std::vector<Student>,CompareStudentNeededTime> TakingTestStudents;

    TakingTestList TakingTestStudents;
    
    StudentQueue studentQueue;
    std::stack<uint8_t> ToBeChecked;

    bool justChecking = false;
    short lastTimePickUp = 0; //time since last pickup
    uint8_t checkingCurrently = 0; // what is the lecturer checking
    std::stack<uint8_t> Finished;

    uint8_t lectureComingTime = 0;
    uint8_t lectureCheckingTime = 0;

};
#endif