#include <iostream>

void concatenate(char* destination, char* source){
    int n = 0;
    for (int i = 0; i < 100; i++)
    {
        if(destination[i] != 0){
            n++;
        }else{
            break;
        }
    }
    


    for(int i =0;i<100;i++){
        if(source[i] == 0){ destination[n+i] == 0; return;}
            destination[n+i] =source[i];

    }

}


int main(){
    char sour[100];
    char dest[200];
    std::cout << "To add "; std::cin.getline(sour,100);
    std::cout << "To dest" ; std::cin.getline(dest,100);
    concatenate(dest,sour);

    for (int i = 0; i < 200; i++)
    {
        if(dest[i] ==0) break;
        std::cout << dest[i];
    }
    

    return 0;
}