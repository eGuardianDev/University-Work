#include <iostream>
using namespace std;
void split(char *s, char *a, char *b){

    int temp[64];
    int countTemp = 0;

    int countA= 0;
    int countB= 0;


        // to do : трябва да се вземе размера на масива "s" иначе няма да работи,
        //          но не помня как се правеше
    for(int i = 0;i <512; i++){
        
        if(s[i] != ' '){
            temp[countTemp] = s[i];
            countTemp++;
        }else{
            
            bool flag = true;
            for(int j =0; j< countTemp; j++){
                char t = temp[j];

                //range of small characters is ascii
                if((int)t >= 95 && (int)t <= 122){
                    // character is small
                }else{
                    //character is not small
                    flag == true;
                    break;
                }
            }

            if(flag == true){
                //add to a
                for(int j =0 ;j< countTemp; j++){
                    a[countA] = temp[j];
                    countA++;
                }
                a[countA] = ' ';
                countA++;
            }else{

                // add to b
                for(int j =0 ;j< countTemp; j++){
                    b[countB] = temp[j];
                    countB++;
                }
                b[countB] = ' ';
                countB++;
            }

            //clear
            countTemp = 0;
        }

        
    }

}

int main(){
    //не работи...
    char s[512];
    cin.getline(s,512);


    char small[256];
    char notSmall[256];
    split (s, small,notSmall);

    cout << small << endl;
    cout << notSmall << endl;





    return 0;
}