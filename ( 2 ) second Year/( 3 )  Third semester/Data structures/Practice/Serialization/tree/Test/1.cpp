#include <iostream>
#include <fstream>
#include <stdexcept>

void readTree(const char* path){

    std::fstream file;
    file.open(path);
    if(!file.is_open())
        throw std::invalid_argument("file not found");
    
    
    char input[255];
    file.getline(input,255);
    std::cout << input << std::endl;
    file.close();
}
void writeTree(const char* path){
    std::ofstream file;
    file.open(path);
    if(!file.is_open())
        throw std::invalid_argument("file not found");
    
    // file.write("cat",2);
    file.write("cat is cool",5);
    file.write("cat is cool",5);
    file.put('a');
    
    file.close();
}

int main(){
    readTree("input.txt");
    writeTree("output.txt");
    return 0;
}