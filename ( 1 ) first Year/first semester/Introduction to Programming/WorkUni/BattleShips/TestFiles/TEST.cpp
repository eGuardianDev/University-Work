#include<iostream>

int main() {
    char c;
   // Set the terminal to raw mode
   /*
   while(1) {
        std::cout << "nuts" << std::endl;
        system("stty raw");
        c = getchar(); 
        // terminate when "." is pressed
        system("stty cooked");
       // system("clear");
        std::cout << (int) c << " was pressed."<< std::endl;
        if(c == 68) std::cout << "Yes";
        if(c == '.') { //66 donw // 67 left // 65 up //68 left
            system("stty cooked");
            exit(0);
        }  
    }
   */
    printf("Hello World");
    printf("\033[%d;%dHello", 9, 4);
    printf("Nuts");
    
}
