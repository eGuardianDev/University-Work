
#include "../src/Headers/TakingTestList.hpp"
#include "../src/Headers/Student.hpp"
#include "../src/Headers/Board.hpp"
#include "../src/Headers/PeopleOnBoard.hpp"
#include "../src/Headers/StudentQueue.hpp"
#include "../src/Headers/MainLogic.hpp"



#include "catch_amalgamated.hpp"

#include <cassert>
#include <sstream>


// Taking Test List
TEST_CASE( "TakingTestList - Push, Pop, Empty")
{
    TakingTestList list;
    

    REQUIRE(list.empty() == true);

    Student temp = Student(0,123,12,0);
    list.push(temp);
    REQUIRE(list.empty() == false);
    list.push(Student(0,2,5,0));

    Student s1 = list.front();
    REQUIRE(s1.getTimeNeeded() == 5);
    list.pop();
    REQUIRE(list.empty() == false);
    Student s2 = list.front();
    REQUIRE(s2.getTimeNeeded() == 12);
    list.pop();
    REQUIRE(list.empty() == true);


    list.push(Student(0,2,5,0));
    list.push(Student(0,2,5,0));
    list.push(Student(0,2,5,0));
    list.clear();
    REQUIRE(list.empty() == true);

}

TEST_CASE("TakingTestList - Testing copy inital constructor"){

    TakingTestList list;

    list.push(Student(0,0,0,0));

    REQUIRE(list.empty() == false);

    TakingTestList list2(list);
    REQUIRE(list2.empty() == false);
    list2.pop();
    REQUIRE(list2.empty() == true);
    REQUIRE(list.empty() == false);
}

TEST_CASE("TakingTestList - Testing copy operator="){

    TakingTestList list;

    list.push(Student(0,0,0,0));

    REQUIRE(list.empty() == false);

    TakingTestList list2;
    list2 = list;
    REQUIRE(list2.empty() == false);
    list2.pop();

    REQUIRE(list2.Size() ==0);
    REQUIRE(list.Size() ==1);
    
    REQUIRE(list2.empty() == true);
    REQUIRE(list.empty() == false);
}

// Board

TEST_CASE("Board - Initialization and cleaning 1x1"){
   
    Board b;

    REQUIRE(b.isInited() == false);
    
    b.InitBoard(1,1);

    REQUIRE(b.isInited() == true);

    REQUIRE(b.getRows() == 1);
    REQUIRE(b.getCollums() == 1);
    
    b.Destruct();
    
    REQUIRE(b.isInited() == false);
    REQUIRE(b.getRows() == 0);
    REQUIRE(b.getCollums() == 0);
}

TEST_CASE("Board - Testing rows and collums if correct 2x1"){
    
    Board b;

    REQUIRE(b.isInited() == false);

    b.InitBoard(2,1);

    REQUIRE(b.isInited() == true);
    REQUIRE(b.getRows() == 2);
    REQUIRE(b.getCollums() == 1);

    
    b.Destruct();
    REQUIRE(b.isInited() == false);
    REQUIRE(b.getRows() == 0);
    REQUIRE(b.getCollums() == 0);
}


TEST_CASE("Board - Index to Pair/Cordinates"){
    
    Board b;

    b.InitBoard(2,2);

    Pair<short> a = b.IndexToPair(0);

    REQUIRE(a.first ==0);
    REQUIRE(a.second == 0);

    a = b.IndexToPair(2);

    REQUIRE(a.first ==1);
    REQUIRE(a.second == 0);


    b.setOnPosition(0,0, Person);
    REQUIRE(b.getOnPosition(0) == Person);

    b.Clean();

    b.setOnPosition(0, Person);
    REQUIRE(b.getOnPosition(0,0) == Person);

    

}
TEST_CASE("Board - 1x1 Get,Set,Check position"){
    Board b;
    b.InitBoard(1,1);

    REQUIRE(b.canPlaceOnPos(0) == true);
    REQUIRE(b.canPlaceOnPos(1) == false);
    REQUIRE(b.isValidPos(0,0) == true);
    
    REQUIRE_FALSE(b.isValidPos(1,0));
    REQUIRE_FALSE(b.isValidPos(0,1));
    REQUIRE_FALSE(b.isValidPos(0,-1));
    REQUIRE_FALSE(b.isValidPos(-1,0) );

    REQUIRE(b.getOnPosition(0) == valid);
    b.setOnPosition(0,invalid);
    REQUIRE(b.getOnPosition(0) == invalid);

    REQUIRE_FALSE(b.canPlaceOnPos(0,0));
    REQUIRE_FALSE(b.canPlaceOnPos(0));

    REQUIRE(b.isValidPos(0,0) == true);

    b.setOnPosition(0,Broken);
    REQUIRE(b.isValidPos(0,0) == true);
    REQUIRE_FALSE(b.canPlaceOnPos(0,0));
    REQUIRE_FALSE(b.canPlaceOnPos(0));
}

TEST_CASE("Board - 2x2 Get,Set,Check position"){
    Board b;
    b.InitBoard(2,2);

    REQUIRE(b.canPlaceOnPos(0) == true);
    REQUIRE(b.canPlaceOnPos(3) == true);

    REQUIRE(b.isValidPos(0,0) == true);
    REQUIRE(b.isValidPos(1,0) == true);
    REQUIRE(b.isValidPos(0,1) == true);
    REQUIRE(b.isValidPos(1,1) == true);

    REQUIRE(b.getOnPosition(0) == valid);
    b.setOnPosition(0,invalid);

    REQUIRE(b.getOnPosition(0) == invalid);
    REQUIRE(b.getOnPosition(1) == valid);
    
    b.setOnPosition(1,Broken);
    
    REQUIRE(b.getOnPosition(0) == invalid);
    REQUIRE(b.getOnPosition(1) == Broken);
    
    REQUIRE_FALSE(b.canPlaceOnPos(0));
    REQUIRE_FALSE(b.canPlaceOnPos(1));
    REQUIRE(b.canPlaceOnPos(2) == true);
    REQUIRE(b.canPlaceOnPos(3) == true);
}

TEST_CASE("Board - Cleaning 2x2"){
    
    Board b;


    b.InitBoard(2,2);

    REQUIRE(b.isInited() == true);
    REQUIRE(b.getRows() == 2);
    REQUIRE(b.getCollums() == 2);

    b.Clean();

    REQUIRE(b.isInited() == true);
    REQUIRE(b.getRows() == 2);
    REQUIRE(b.getCollums() == 2);

    b.setOnPosition(0, Broken);
    b.Clean();
    REQUIRE(b.getOnPosition(0) == valid);
}

TEST_CASE("PeopleOnBoard - 2x2 - Placing and removing people"){
    Board b;
    b.InitBoard(2,2);

    REQUIRE(b.canPlaceOnPos(0) == true);
    REQUIRE(b.canPlaceOnPos(3) == true);

    setPerson(b, 0,0);
    
    REQUIRE(b.getOnPosition(0) == Person);

    for(int i =1;i<4;++i){
           REQUIRE(b.getOnPosition(i) == invalid);
    }

    REQUIRE(b.canPlaceOnPos(0) == false);
    REQUIRE(b.canPlaceOnPos(3) == false);

    removePerson(b,0,0);
    for(int i =0;i<4;++i){
        REQUIRE(b.getOnPosition(i) == valid);
    }

    REQUIRE(b.canPlaceOnPos(0) == true);
    REQUIRE(b.canPlaceOnPos(3) == true);

}
TEST_CASE("PeopleOnBoard - 2x3 - Placing and removing people"){
    Board b;
    b.InitBoard(2,3);


    setPerson(b, 0,0);
    setPerson(b, 0,2);

    REQUIRE(b.getOnPosition(0) == Person);     
    REQUIRE(b.getOnPosition(1) == invalid);     
    REQUIRE(b.getOnPosition(2) == Person);     

    for(int i =0;i<3;++i){
        REQUIRE(b.getOnPosition(3+i) == invalid);     
    }

    removePerson(b,0,0);

    REQUIRE(b.getOnPosition(0) == valid);     
    REQUIRE(b.getOnPosition(1) == invalid);     
    REQUIRE(b.getOnPosition(2) == Person);     

    REQUIRE(b.getOnPosition(3) == valid);     
    for(int i =0;i<2;++i){
        REQUIRE(b.getOnPosition(4+i) == invalid);     
    }
}

TEST_CASE("PeopleOnBoard - 3x3- Running algorthim for configurations"){
    Board b;
    b.InitBoard(3,3);

    REQUIRE(findPeopleInRoom(b) == 4);

    b.Clean();

    b.setOnPosition(0,Broken);

    REQUIRE(findPeopleInRoom(b) == 3);

    b.Clean();

    b.setOnPosition(0,Broken);
    b.setOnPosition(2,Broken);

    REQUIRE(findPeopleInRoom(b) == 3);

    b.Clean();

    b.setOnPosition(0,Broken);
    b.setOnPosition(1,Broken);
    b.setOnPosition(2,Broken);

    REQUIRE(findPeopleInRoom(b) ==2);
 b.Clean();

    b.setOnPosition(0,Broken);
    b.setOnPosition(1,Broken);

    REQUIRE(findPeopleInRoom(b) ==3);

    b.Clean();

    b.setOnPosition(0,Broken);
    b.setOnPosition(1,Broken);
    b.setOnPosition(2,Broken);
    b.setOnPosition(3,Broken);
    b.setOnPosition(4,Broken);
    b.setOnPosition(6,Broken);
    b.setOnPosition(7,Broken);
    b.setOnPosition(8,Broken);

    REQUIRE(findPeopleInRoom(b) ==1);

}
TEST_CASE("Board - Printing"){
    
    Board b;
    

    short count = 1;

    std::stringstream output;
    std::stringstream desiredOuput;
    for(int j =1; j<=3;++j){

        count=j;

        b.InitBoard(count,count);

        //generate for test case
        for(int i =0;i<count;++i){
            desiredOuput << std::string(count, valid);
            if(i < count) desiredOuput << std::endl;
        }

        b.PrintBoard(output);

        REQUIRE(desiredOuput.str() == output.str());
        
        b.Destruct(); 
    }

    b.InitBoard(3,3);

    setPerson(b, 0, 0);
    
    b.setOnPosition(8, Broken);
    b.PrintBoard(output);


}

//Student queue

TEST_CASE("Student queue - main functions"){
    StudentQueue sq;
    
    REQUIRE(sq.isEmpty());

    sq.push(Student(1,2,3,4));

    REQUIRE_FALSE(sq.isEmpty());

    Student stud = sq.front(0);

    REQUIRE(stud.getId() == 2);

    sq.pop(0);

    REQUIRE(sq.isEmpty());

}
TEST_CASE("Student queue - priority test"){
    StudentQueue sq;
    
    REQUIRE(sq.isEmpty());

    sq.push(Student(1,4,3,4));
    sq.push(Student(1,2,3,2));

    REQUIRE_FALSE(sq.isEmpty());

    Student stud = sq.front(3);

    REQUIRE(stud.getId() == 2);

    sq.pop(3);

    REQUIRE_FALSE(sq.isEmpty());

    stud = sq.front(3);
    sq.pop(3);
    REQUIRE(stud.getId() == 4);



    REQUIRE(sq.isEmpty());

    sq.push(Student(1,4,3,4));
    sq.push(Student(1,2,3,2));

    REQUIRE_FALSE(sq.isEmpty());
    stud = sq.front(0);

    REQUIRE(stud.getId() == 4);

    sq.pop(0);

    REQUIRE_FALSE(sq.isEmpty());

    stud = sq.front(3);

    REQUIRE(stud.getId() == 2);
    REQUIRE_FALSE(sq.isEmpty());

}


//Main logic


TEST_CASE("Main logic - default parameters - Read file"){

    MainLogic ml;
    
    REQUIRE_THROWS(ml.ReadFromFileCommands("randomTextForTestingPleaseDontCreateThis.txt"));

    std::queue<uint8_t> test = ml.ReadFromFileCommands("inputDefault.txt");

    REQUIRE(test.front() ==6); test.pop();
    REQUIRE(test.front() ==7); test.pop();
    for(int i =0;i<6;++i) test.pop();
    REQUIRE(test.front() ==0); 
    for(int i =0;i<3;++i) test.pop();
    REQUIRE(test.front() ==2);

}

TEST_CASE("Main logic - default parameters - Board"){

    MainLogic ml;
    
    std::stringstream output;
    std::stringstream desiredOutput;
    
    ml.LoadInputFromFile("inputDefault.txt");

    ml.getBoard().PrintBoard(output);
        //generate for test case
    desiredOutput
    << std::string(7,valid) << std::endl
    << (char)valid<<(char)valid<<(char)Broken<<std::string(4,valid)<< std::endl
    <<std::string(5,valid)<<(char)Broken<<(char)valid << std::endl
    <<std::string(7,valid) << std::endl
    <<(char)valid<<(char)Broken<<std::string(5,valid) << std::endl
    << std::string(7,valid)<< std::endl;

    REQUIRE(output.str() == desiredOutput.str());


    REQUIRE(ml.FindPlacesForPeople()==12);

    ml.getBoard().PrintBoard(output);

    desiredOutput.clear();

    desiredOutput << "OFOFOFO"<< std::endl
                  << "FFBFFFF"<< std::endl
                  << "OFOFOBO"<< std::endl
                  << "FFFFFFF"<< std::endl
                  << "OBOFOFO"<< std::endl
                  << "FFFFFFF"<< std::endl;
    REQUIRE(output.str() == desiredOutput.str());

}

TEST_CASE("Main logic - default parameters - Student finish queue"){

    MainLogic ml;
    ml.LoadInputFromFile("inputDefault.txt");
    ml.FindPlacesForPeople();

    REQUIRE_FALSE(ml.canOutput());

    int time =0;
    for( ;;++time){
        ml.CheckForFinishingStudents(time);
        while(ml.TryLettingNextStudentIn(time));
        ml.LectureCheck(time);
        if(ml.isEveryoneFinished()) break;
    }

    
    std::stringstream output;
    std::stringstream desiredOutput;
    desiredOutput <<"246"<< std::endl
                    << "119"<< std::endl
                    << "5"<< std::endl
                    << "180"<< std::endl
                    << "203"<< std::endl
                    << "159"<< std::endl
                    << "221"<< std::endl
                    << "40"<< std::endl
                    << "235"<< std::endl
                    << "72"<< std::endl
                    << "101"<< std::endl
                    << "62"<< std::endl
                    << "234"<< std::endl
                    << "231"<< std::endl
                    << "176"<< std::endl
                    << "53"<< std::endl
                    << "208"<< std::endl
                    << "34"<< std::endl
                    << "213"<< std::endl
                    << "167"<< std::endl;
    REQUIRE(ml.canOutput());
    ml.outputFinished(output);
    REQUIRE(desiredOutput.str() == output.str());
}