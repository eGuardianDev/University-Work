#include <iostream>
#include <vector>



int DisplayBoard(std::vector<int> data, int size){
    int count = 0;
    for(auto a: data){
        if(count ==size){
            count = 0;
            std::cout << std::endl;
        }
        count++;
        std::cout << a << " ";
    }
        std::cout << std::endl;
    return 0;
}

// this made the program 1e10000x times faster
std::vector<int> Xpos = { 2, 1, -1, -2, -2, -1, 1, 2 };
std::vector<int> Ypos =  { 1, 2, 2, 1, -1, -2, -2, -1 };

bool RecursionOnBoard(std::vector<int> board, int x, int y, int size, int currentPos){ 
 

    // if(board[x + size*y] !=0)return 0;
    
    board[x + size*y] = currentPos;

    if(currentPos ==(size*size)) {
        DisplayBoard(board,size );
        return 1;
    }
    bool flag = false;
    currentPos++;
    int newX, newY;
    for( int i = 0;i< 8;i++){

        newX = x+Xpos[i];
        newY = y+Ypos[i];
        if(newX< 0 ||newX  >= size) continue;
        if(newY < 0 || newY >= size) continue;
        if(board[newX + size*newY] !=0) continue;

        
        if(RecursionOnBoard(board, newX, newY,size, currentPos)) return 1;
        
    }
    board[x + size*y]= 0;
    return 0;
}

void RecursionOnBoard(int size, int x, int y){
    RecursionOnBoard(std::vector<int>(size*size), x,y, (size),1);
}


int main(){
    int x,y,sizeOfBoard;
    std::cin >> sizeOfBoard >> x >> y;
    

    RecursionOnBoard(sizeOfBoard, x,y);

    return 0;
}