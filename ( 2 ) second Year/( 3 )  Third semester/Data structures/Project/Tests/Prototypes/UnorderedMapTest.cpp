#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../Objects.hpp"
void test1(){

    std::unordered_multimap<std::string,int> list;


    list.insert({"cat",1});
    list.insert({"dog",2});
    list.insert({"cat",5});
    list.insert({"truck",-1});


    std::cout << list.size() << '\n';
    // std::cout << list.bucket("truck") << '\n';

    
    for(auto it = list.begin(); it != list.end(); ++it){
        // std::cout << it->first << " " << it->second << std::endl;
        auto [begin,end] = list.equal_range(it->first);
        std::cout << begin->first <<" : " << "{";
        for(auto it = begin; it != end; ++it){
            std::cout <<  it->second << ", ";
        }
        std::cout << "}" << std::endl;
    }



    std::string cmd;
    getline(std::cin, cmd);

    auto [begin, end] =list.equal_range(cmd);
    if(begin != nullptr){

        std::cout << begin->first << ": {" ;
        for(auto it = begin; it != end; ++it){
            std::cout << it->second << " ";
        }
        std::cout << '}' << std::endl;
    }else{
        std::cout << "not found\n";
    }

}

std::vector<std::string> splitString(std::string input){
    std::vector<std::string> splited(0);

    std::string data = "";

    for( char ch :  input ){
        if(ch == ' '){
            if(data.size() > 0){
                splited.push_back(data);
                data = "";
            }
        }else{
            data += ch;
        }
    }

    if(data.size() >0){
        splited.push_back(data);
    }

    return splited;
}
void test2(){

    struct execute{
        int argc;
        std::function<double(std::vector<std::string>)> func;
    };
    std::unordered_multimap<std::string,execute> list;


    list.insert({"ping",{0,[](std::vector<std::string>){std::cout <<"pong"<<std::endl; return 0;}}});
    list.insert({"ping",{1,[](std::vector<std::string> args){std::cout <<"pong, " << args[1]<<std::endl; return 0;}}});
    list.insert({"add",{2,[](std::vector<std::string> args){return std::stod(args[1]) + stod(args[2]);}}});



    std::string cmd;
    getline(std::cin, cmd);

    std::vector<std::string> splitCmd = splitString(cmd);


    if(splitCmd.size() > 0){
        auto [begin, end] = list.equal_range(splitCmd[0]);    
        if(begin == nullptr){
            std::cout << "Error: cmd not found\n";
        }else{
            int argc = splitCmd.size() -1;
            while(begin != end){
                if(begin->second.argc == argc){
                    std::cout << begin->second.func(splitCmd) << std::endl;
                    break;
                }
                ++begin;
            }
            if(begin == end){
                std::cout << "Invalid argument count";
            }
            // data->second.func(std::vector<std::string>(0));
        }
    }else{
        std::cout << "invalid input size" << std::endl;
    }


}


bool isNum(std::string input){
    for(int i=0;i<input.size();++i){
        if(input[i] < '0' || input[i] > '9'){
            return false;
        }
    }
    return true;
}
void test3(){

    struct execute{
        int argc;
        std::function<double(std::vector<Object*>)> func;
    };
    std::unordered_multimap<std::string,execute> list;


    list.insert({"ping",{0,[](std::vector<Object*>){std::cout <<"pong"<<std::endl; return 0;}}});
    list.insert({"ping",{1,[](std::vector<Object*> args){std::cout <<"pong, " << (*args[0])() <<std::endl; return 0;}}});
    list.insert({"add",{2,[](std::vector<Object*> args){return (*args[0])() + (*args[1])();}}});



    while(true){

    std::string cmd;
    getline(std::cin, cmd);

    std::vector<std::string> splitCmd = splitString(cmd);


    if(splitCmd.size() > 0){
        auto [begin, end] = list.equal_range(splitCmd[0]);    
        if(begin == nullptr){
            if(splitCmd[1] == "<-"){
                list.insert({
                    splitCmd[0],
                    {0, [splitCmd](std::vector<Object*> args){
                        std::cout << "Im a new function " << splitCmd[0] <<std::endl;
                        return 0;
                    }}
                });
                std::cout << "Added new command" << std::endl;
                continue;
            }
            std::cout << "Error: cmd not found\n";
        }else{
            if(splitCmd[1] == "<-"){
                std::cout << "This function already exists " << std::endl;
                continue;
            }
            int argc = splitCmd.size() -1;
            while(begin != end){
                if(begin->second.argc == argc){
                    std::vector<Object*> args(0);
                    for(int i =1;i<splitCmd.size();++i){
                        if(isNum(splitCmd[i])){
                            args.push_back(new RealNumber(std::stod(splitCmd[i])));
                        }else{
                            std::cout << "invalid argument" << std::endl;
                            return;
                        }
                    }
                    std::cout << begin->second.func(args) << std::endl;
                    break;
                }
                ++begin;
            }
            if(begin == end){
                std::cout << "Invalid argument count\n";
            }
            // data->second.func(std::vector<std::string>(0));
        }
    }else{
        std::cout << "invalid input size" << std::endl;
    }

    }
}

int main(){
    // test1();
    // test2();
    test3();
}