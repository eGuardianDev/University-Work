
#include "../src/Headers/TakingTestList.hpp"
#include "../src/Headers/Student.hpp"
#include "../src/Headers/Board.hpp"
#include "../src/Headers/PeopleOnBoard.hpp"



#include "catch_amalgamated.hpp"

#include <cassert>


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
TEST_CASE("Board - 1x1 Get,Set,Check position"){
    Board b;
    REQUIRE(b.isInited() == false);
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
    REQUIRE(b.isInited() == false);
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

    REQUIRE(b.isInited() == false);

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
    REQUIRE(b.isInited() == false);
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
    REQUIRE(b.isInited() == false);
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
    REQUIRE(b.isInited() == false);
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

}
