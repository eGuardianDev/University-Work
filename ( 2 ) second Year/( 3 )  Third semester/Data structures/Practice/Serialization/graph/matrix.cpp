#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

typedef std::vector<std::vector<int>> graph; 

std::vector<int> split(std::string data){

    std::vector<int> res;
    int num =0;
    int dir = 1;
    for(int i =0;i<data.size();++i){
        if(data[i] == ' '){
            res.push_back(num * dir);
            dir = 1;
            num = 0;
        }
        else if(data[i] == '-'){
            dir = -1;
        }else{
            num *= 10;
            num += data[i]-'0';
        }
    }
    res.push_back(num *dir);
    return res;
}

void readMatrix(graph& graph){

    std::fstream file("matrix.txt");
    std::string data;

    int rowIndex =0;
    while(getline(file, data)){
        std::vector<int> row = split(data);
        graph.push_back(std::vector<int>(0));
        for(int i =0;i<row.size();++i){
            graph[rowIndex].push_back(row[i]);
        }
        rowIndex++;
    }
    file.close();
}
void print(graph& graph){

    for(int i =0;i<graph.size();++i){
        for(int j =0;j<graph[i].size(); ++j){
            std::cout << graph[i][j] ;
        }
        std::cout << std::endl;
    }

}



int main(){
    graph graph;
    readMatrix(graph);
    print(graph);


    return 0;
}