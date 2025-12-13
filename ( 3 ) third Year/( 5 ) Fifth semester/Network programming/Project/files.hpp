#ifndef FILES_HPP__
#define FILES_HPP__

#include <unistd.h>
#include <string>
#include <fcntl.h>
#include "./ImageProcessing/BMP_File.hpp"
#include "./ImageProcessing/BMP_Manipulation.hpp"

bool validate_input_file(std::string name){
    if(name.length() < 4) {
        std::cerr << "file must contain extension '.bmp'" <<std::endl;
        return false;
    }
    std::string type =name.substr(name.length() - 4);
    if(type != ".bmp"){
        std::cerr << "File doesn't end with bmp image." << std::endl;
        return false;
    }
    return true;
}
int load_image(std::string name, bool &status){

    int fd = open(name.c_str(), O_RDONLY);

    if(fd == -1){
        std::cerr << "Error openning file." << name << std::endl;
    }
    return fd;
}
bool load_file(std::string name, std::string &global_name, int &fd){
    bool status;
    if(!validate_input_file(name)) return false;      // check file name and extensions
    int new_fd = load_image(name,status);           // loading file;
    if(new_fd == -1) return false;                // file didn't open 
    if(!validate_file(new_fd)) return false;      // file is invalid in size or signature
    if(fd >2) close(fd);
    fd = new_fd;
    global_name= name;
    return true;
}

#endif //FILES_HPP__
