
#include "../src/Headers/TakingTestList.hpp"
#include "../src/Headers/Student.hpp"



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

