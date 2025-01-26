
#include "./headers/MainLogic.hpp"

int main(int argc, char * argv[]){

    MainLogic ml;

    if(argc == 2){
        ml.ReadFromFile(argv[1]);
        ml.CLI();
    }else if (argc == 1 ){
        ml.CLI();
    }else{
        std::cout << "Too many arguments passed when calling program" << std::endl;
        return 1;
    }

    return 0;
}