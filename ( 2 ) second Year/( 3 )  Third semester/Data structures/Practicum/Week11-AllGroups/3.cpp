
#include <iostream>
#include <vector>


void canVisitAllRooms(std::vector<std::vector<int>>& rooms, std::vector<bool>& visited, int start = 0) {    
    visited[start] = true;
    for(int i =0;i<rooms[start].size();++i){
        if(visited[rooms[start][i]] == false){
            canVisitAllRooms(rooms, visited, rooms[start][i]);
        }
    }
}

bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {    
    std::vector<bool> visited(rooms.size(), false);
   
    canVisitAllRooms(rooms,visited);

    for(int i =0;i<visited.size();++i){
        if(visited[i] == false) return false;
    }
    return true;
}

int main(){
    std::vector<std::vector<int>> list
    = {{1},{2},{3},{}};   
    std::cout << canVisitAllRooms(list);
}