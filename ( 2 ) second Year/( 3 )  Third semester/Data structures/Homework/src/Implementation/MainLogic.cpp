#include "../Headers/MainLogic.hpp"
#include <fstream>
#include "../Headers/PeopleOnBoard.hpp"

std::queue<uint8_t> MainLogic::ReadFromFileCommands(std::string path){


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

void MainLogic::LoadInputFromFile(std::string path){

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



bool MainLogic::TryLettingNextStudentIn(int time){
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

short MainLogic::CheckForFinishingStudents(int time){

    assert(Room.isInited());
    assert(AvailableSeats > 0);

    if(TakingTestStudents.empty()) return 0;
    int count =0; //students exiting the room
    
    Student curr = TakingTestStudents.front();
    while(!TakingTestStudents.empty()){

        curr = TakingTestStudents.front();

        if(curr.getTimeComing() + curr.getTimeNeeded()>time) return count;

        TakingTestStudents.pop();
        ToBeChecked.push(curr.Id);
        ++count;

    
    }
    return count;
}


int MainLogic::FindPlacesForPeople(){
    assert(Room.isInited());
    AvailableSeats = findPeopleInRoom(Room);
    return AvailableSeats;
}

const Board& MainLogic::getBoard() const {
    return Room;
}


void MainLogic::LectureCheck(int time){
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

void MainLogic::outputFinished(std::ostream& stream){
    while(!Finished.empty())
    {
        stream << (int)Finished.top()+1 << '\n'; Finished.pop();
    }
}



bool MainLogic::isEveryoneFinished() const{
    return ToBeChecked.empty() && checking==false && TakingTestStudents.empty() && studentQueue.isEmpty(); 
}

short MainLogic::EmptySeats() const{
    return AvailableSeats - TakingTestStudents.Size();
}