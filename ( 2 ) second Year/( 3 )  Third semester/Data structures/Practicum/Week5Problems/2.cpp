
#include <iostream>
#include <queue>


struct Point{
    int x,y, step;
    Point(int x, int y,int step) : x(x), y(y), step(step){ }
};

int xChange[] = {1,1,-1,-1,2,2,-2,-2};
int yChange[] = {2,-2,2,-2,1,-1,1,-1};

bool CheckIfInside(int n, int x,int y){
    return (x < n && y <n && y>=0 && x >= 0);
}

int StepOnBoardsByHorse(const size_t n, int startX, int startY, int endX, int endY)
{
    std::queue<Point> queue;
    std::vector<bool> beenThere(n*n);
    
    queue.push(Point(startX,startY,0));
    
    while(!queue.empty())
    {
        Point curr = queue.front(); queue.pop();
        if(curr.x == endX && curr.y == endY){
            return curr.step;
        }
        for(size_t i = 0; i<8;++i){
            int tempX = curr.x + xChange[i];
            int tempY = curr.y +yChange[i];
            if(CheckIfInside(n, tempX, tempY) && !beenThere[tempX + n* tempY]){
                queue.push(Point(curr.x + xChange[i],curr.y+yChange[i],curr.step+1));
                beenThere[tempX + n * tempY] = true;
            }  
        }
    }
    return -1;
}

int main(){

    std::cout << StepOnBoardsByHorse(4, 0, 0,
     4, 1);
     return 0;
}