
#include "MenuFunctions.h"
#include <iostream>
#include <fstream>

void PrintBox(std::string text, int spaceBefore){
    PrintChars(' ', spaceBefore);
    std::cout << '/';PrintChars('-', text.length()+2); std::cout << '\\' << std::endl;
    PrintChars(' ', spaceBefore);
    std:: cout << "| " << text << " |\n";  
    PrintChars(' ', spaceBefore);

    std::cout << '\\';PrintChars('-', text.length()+2); std::cout << '/' << std::endl;
    
}
void PrintChars(char c, int Count){
    for(int i =0; i < Count ; i++){
        std::cout << c;
    }
}   


std::string GetLogo(std::string file){
    std::string file_data;
    std::ifstream fileStreamOut (file);
    std::string line ;

    if (!fileStreamOut.is_open())
    {
        std::cout << "Error Opening a file " << file;
    }


    while ( getline (fileStreamOut,line) )
    {
        //std::cout << line << "\n"
        file_data += line + '\n'; 
    }


    fileStreamOut.close();
    return file_data;
}