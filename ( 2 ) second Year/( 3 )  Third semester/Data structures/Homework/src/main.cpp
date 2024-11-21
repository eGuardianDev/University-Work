
#include <iostream>

#include "Headers/Board.hpp"
#include "Headers/MainLogic.hpp"



int main(){

    MainLogic ml;
    ml.LoadInputFromFile();
    int peopleInRoom = ml.FindPlacesForPeople();

    ml.getBoard().PrintBoard(std::cout);

  
    int i =0;
    for( ;;++i){

        ml.CheckForFinishingStudents(i);
        while(ml.TryLettingNextStudentIn(i));
        
        
        ml.LectureCheck(i);

        
        if(ml.isEveryoneFinished()) break;
        if(i == 500) break;
    }
    std::cout << "Time: " << i << '\n';

    ml.outputFinished(std::cout);
    // ml.outputToCheck(std::cout); // Debug
    return 0;
}