#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <fcntl.h>
#include <unistd.h>

#include "CLI.hpp"
#include "files.hpp"

enum Command{
    C_help,
    C_load,
    C_check,
    C_send,
    C_leave,
    C_list,
    C_clear,
    C_none
};

Command getCommand(std::string &input){
    if(input == "help")       return Command::C_help;
    else if(input == "load")  return Command::C_load;
    else if(input == "check") return Command::C_check;
    else if(input == "send")  return Command::C_send;
    else if(input == "exit")  return Command::C_leave;
    else if(input == "ls")    return Command::C_list;
    else if(input == "clear") return Command::C_clear;
    return C_none; 
}


int main(){
    system("clear");
    printLogo(std::cout);
    printCommands(std::cout);

    std::string file_name;
    int fd = -1;
    while(1){
        bool status;
        std::string inputCLI;
        std::cout << file_name<< "> ";
        std::getline(std::cin, inputCLI);
    
        std::vector<std::string> cmd = split(inputCLI, ' ');
        cmd[0] = toLower(cmd[0]);
        switch(getCommand(cmd[0])){
            case Command::C_help:
                printCommands(std::cout);
                break;
            case Command::C_check:

                break;
            case Command::C_send:
                if(fd < 2 || file_name == ""){
                    std::cerr << "No image selected" << std::endl;
                    continue;
                }
                if(cmd.size() == 2) menu_send(fd, file_name,cmd[1]);
                else menu_send(fd, file_name);
                break;
            case Command::C_load:
                if(cmd.size() != 2){
                    std::cerr << "Expected 1 arguments, received " << cmd.size()-1 << std::endl;
                    continue;
                }
                if(loadFile(cmd[1],file_name,fd))
                    std::cout << "Opened file!" << std::endl;
                break;
            case Command::C_leave:
                if(fd) close(fd);
                return 0;
            case Command::C_list:
                system("ls");
                break;
            case Command::C_clear:
                system("clear");
                break;
            default:
                std::cout << "Command is not recognized." << std::endl;
        }
        
        
    }
        
    return 0;
}