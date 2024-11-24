
#include <exception>
#include <iostream>
#include <stdexcept>

// #include "Headers/Board.hpp"
#include "Headers/MainLogic.hpp"

MainLogic ml;
int Timer = 0;

void Initialize(std::string InputFile = "./input.txt"){
    ml.LoadInputFromFile(InputFile);
    ml.FindPlacesForPeople();
}

void RunLogic(){
    int time =0;
    for( ;;++time){
        ml.CheckForFinishingStudents(time);
        while(ml.TryLettingNextStudentIn(time));
        ml.LectureCheck(time);
        if(ml.isEveryoneFinished()) break;
    }
    Timer = time;
}

void OutputData(std::ostream& stream ){
    
    ml.getBoard().PrintBoard(stream);
    if(!ml.canOutput()){
        throw std::invalid_argument("The data was outputed or there is nothing to output yet");
    }
    ml.outputFinished(stream);
    int minutes = Timer;
    int hours = 0;
    while(minutes >= 60) {
        ++hours; minutes-=60;
    }
    std::cout << "Time: " << 8+hours << ":";
    if(minutes< 10) std::cout << "0";
    std::cout <<minutes << '\n';
}

int main(){

    Initialize();
    RunLogic();
    OutputData(std::cout);
  

    return 0;
}