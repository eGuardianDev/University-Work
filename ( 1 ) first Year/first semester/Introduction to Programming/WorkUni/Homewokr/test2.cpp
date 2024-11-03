#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main(){

    int n = 0;
    
    string line;
    int b =-1;
    int sum = 0;
    int placeOfNumber =0 ;

    // използвах това защото cin прави проблем
    // така чета всеки ред сам по себе си
    // очаква се потребителя да въведе точни стойности
    while (getline(cin, line)) {
        if(b<0){
            n = stoi(line);
        }else{
            
            std::istringstream is( line );
            int temp =0;
            while( is >> temp ) {
                if(temp == 1){

                sum ^= placeOfNumber;
                }
                placeOfNumber++;    
            }
            
            
  
            if(b == log2(n)*2 -1) break;
        }
        b++;
    }
    cout << sum;

    return 0;
}

/*

    1 0 0 1 1 0 1 0 1 1 1 1 0 1 1 0
    1 0 1 0 1 1 1 0 0 0 0 0 0 1 0 0
    1 0 1 1 0 1 1 0 1 0 0 0 0 1 1 0
    0 1 1 1 0 1 1 0 1 0 0 0 0 1 1 0
    1 1 1 0 0 1 1 0 1 0 1 0 0 1 1 0
    0 0 1 0 0 1 1 0 0 0 0 0 0 1 0 0
    0 0 1 0 1 1 1 0 1 1 1 1 0 1 1 0
    0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 0
    1 0 0 1 0 1 1 0 0 1 1 1 0 1 1 0
    0 0 1 0 0 1 1 0 0 0 0 0 0 1 0 0
    0 0 1 0 1 1 1 0 0 0 0 1 0 1 1 0
    1 0 1 0 0 1 1 0 0 0 0 0 0 1 0 0
    1 1 0 0 1 1 1 0 1 0 1 0 0 1 1 0
    1 0 1 0 0 1 1 0 1 1 0 0 0 1 1 0
    0 1 0 0 1 1 1 0 1 0 1 0 0 1 1 0
    0 0 1 0 1 1 1 0 1 0 0 0 0 1 0 0


*/