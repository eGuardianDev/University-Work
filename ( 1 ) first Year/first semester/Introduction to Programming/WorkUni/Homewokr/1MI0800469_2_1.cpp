#include <iostream>
using namespace std;

int main(){
    int hours = 0;
    cin >> hours;

    float time =0 ;
    string day;

        for( int i =0 ;i < 5;i++){

            cin>> day;
            for(int k =0 ;k <day.length(); k+=2){
                char a =day[k];
                char b =day[k+1];
                if(a == 'h' && b == 'w'){
                   time +=1;
                }else if(a == 's' && b == 't'){
                     time +=0.5;
                 }
            }

        }
        cout << ((hours <= time) ? "You got it!" : "You should work more") << endl;
    return 0;
}

