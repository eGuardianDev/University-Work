#include <cstdint>
#include <iostream>

#include "Board.hpp"
#include "Student.hpp"
#include "addons.hpp"
#include "PeopleOnBoard.hpp"
#include "StudentQueue.hpp"


#include <fstream>
#include <queue>
#include <stdexcept>
#include <string>

#include "MainLogic.hpp"


// void TestBoardLoading(){
//     Board b;
//     Board Global;
//     b.InitBoard(5,5);

//     b.setOnPosition(0,Broken);
//     b.setOnPosition(1,Broken);
//     b.setOnPosition(2,Broken);
//     // b.setOnPosition(19,Broken);
//     // b.setOnPosition(29,Broken);
    
//     // std::cout << b.getOnPosition(9);
//     // system("clear");

//     int a = findPeopleInRoom(b,Global);
//     // SetPerson(b,5,0);
//     // removePerson(b,5,0);
//     //!!!can remove at left down


//     // b.PrintBoard(std::cout);
//     Global.PrintBoard(std::cout);
//     std::cout << a;

// }


int main(){

    MainLogic ml;
    ml.LoadInputFromFile();
    int peopleInRoom = ml.FindPlacesForPeople();

    ml.getBoard().PrintBoard(std::cout);

    // std::cout << ml.studentQueue.isEmpty();
    // std::cout<< ml.TryLettingNextStudentIn();
   
    // for(int time =0 ;; ++time){

    //     while(ml.TryLettingNextStudentIn(time));

    //     ml.CheckForFinishingStudents(time);
    //     // if(ml.isEveryoneFinished()) break;
    //     if(ml.TakingTestStudents.empty()) break;
    //     // std::cout << time << '\n';
    // }
    int i =0;
    for( ;;++i){

        ml.CheckForFinishingStudents(i);
        while(ml.TryLettingNextStudentIn(i));
        
        
        ml.LectureCheck(i);

        
        if(ml.isEveryoneFinished()) break;
        if(i == 500) break;
    }
    std::cout << "Time: " << i << '\n';
    // // std::cout << ml.TakingTestStudents.size()<<'\n';
    
    // // std::cout << ml.TakingTestStudents.size();
    // ml.outputToCheck(std::cout);
    ml.outputFinished(std::cout);
// 

    // ml.outputToCheck(std::cout);
    // std::cout << ml.CheckForFinishingStudents(0);
    // std::cout << (int)ml.TakingTestStudents.top().Id;


    // std::cout <<peopleInRoom;
    return 0;
}