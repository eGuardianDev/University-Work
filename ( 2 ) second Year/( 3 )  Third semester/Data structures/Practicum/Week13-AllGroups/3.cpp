#include <climits>
#include <iostream>

#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <vector>

 std::unordered_map<std::string,std::string> readCodes(){
    std::fstream file("airportCodes.txt");

    std::string data;

    std::unordered_map<std::string,std::string> codeCity;
    std::string code;
    std::string output;
    bool cities = false;
    while(getline(file, data)){
        output = code = "";
        cities = false;

        for(char ch : data){
            if(ch == '='){
                cities = true; 
                continue;
            }
            if(cities) output += ch;
            else code += ch;
        }
        codeCity[code] = output;
    }
    return codeCity;
}


std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> readDestinations(){

    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> adjList;

    std::fstream file("destinations.txt");
    std::string from;
    std::string to;
    double w;
    while(!file.eof()){
        file >> from;
        file >> to;
        file >> w;
        adjList[from].push_back(std::pair(to, w));       
        // adjList[to].push_back(std::pair(from, w));
    }
    file.close();
    return adjList;

}


void print(std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& adjList){
    for(auto it = adjList.begin(); it != adjList.end();++it){
        std::cout << it->first << " => ";
        for(auto location : it->second){
            std::cout << location.first << " - " << location.second << ", ";
        }
        std::cout << "\b\b \n";
    }
}


std::string getMin
(std::vector<std::string> names,
    std::unordered_map<std::string,bool>& visited,
          std::unordered_map<std::string,double>& distance){


    int min = INT_MAX;
    std::string index = "";

    for(int i =0;i<names.size();++i){
        if(visited[names[i]] == false && distance[names[i]] < min){
            min = distance[names[i]];
            index = names[i];
        }
    }

    return index;
}

void dijkstra(
   

    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& adjList, std::string start, std::string end){

    std::unordered_map<std::string,bool> visited;
    std::unordered_map<std::string,double> distance;
    std::unordered_map<std::string,std::string> prev;

    std::vector<std::string> list;
    for(auto it = adjList.begin(); it != adjList.end(); it++){
        list.push_back(it->first);
    }

    for(auto a : list){
        visited[a] = false;
        distance[a] = INT_MAX;
        // std::cout << a << "\n";
    }

    distance[start] = 0;
    for(int i =0;i<list.size();++i){
        
        std::string st = getMin(list, visited,distance);

        visited[st] = true;

        std::vector<std::pair<std::string, double>> temp = 
        adjList[st]; 
        for(int k =0;k<temp.size();++k){
            if(visited[temp[k].first] == false
            && distance[st] != INT_MAX
            && distance[temp[k].first] > distance[st] + temp[i].second
            ){
                distance[temp[k].first] = distance[st] + temp[i].second;
                prev[temp[k].first] = st;
            }
        }
    }

    for(auto a = distance.begin() ; a!= distance.end();++a){
        if(a->first == start) continue;
        std::cout << a->first << " " << a->second << " from " << prev[a->first] <<"\n";
    }

    std::string curr =end;

    double price =0;

    auto city = readCodes();

    std::vector<std::string> order;
    order.push_back(end);
    while(curr != start)
    {
        order.push_back(curr);
        price += distance[curr];
        curr = prev[curr];
    }
    order.push_back(start);    
    std::cout << price << '\n';

    for(int i =order.size()-1; i>0;i--)
    {
        std::cout << order[i] << " -> " <<city[order[i]] << "\n"; 
    }





}


int main(){
    // readDestinations();
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> adjList = readDestinations();

    // print(adjList);

    std::string start ="SOF";
    std::string END = "CDG";
    dijkstra(adjList, start,END);

    // BellmanFor(adjList, "Sof");


    return 0;
}