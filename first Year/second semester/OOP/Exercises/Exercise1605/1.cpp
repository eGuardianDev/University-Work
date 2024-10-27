#include <iostream>
#include <vector>
struct Cell{
    int x,y;
    Cell() {x=0; y=0;}
    Cell(int x ,int y): x(x), y(y){}
};

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Object{
    public:
    virtual char draw() = 0;
    virtual std::string location() = 0;
    virtual bool move() = 0;
};

class Person : public Object{
    private:
    Direction direc;
    Cell _location;
    std::string name;
    public:
        Person(){
            this->_location = Cell(0,0);
        }
        Person(int x, int y, std::string name){
            this->_location = Cell(x,y);
            this->name = name;
        }
        Person(Cell location, std::string name){
            this->_location = location;
            this->name = name;
        }
        char draw() override{
            return 'p';
        }
        std::string location() override{

            return "";
        }
        bool move() override{
            switch(direc){
                case UP:
                break;
                case DOWN:
                
                break;
                case LEFT:
                
                break;
                case RIGHT:
                
                break;
            }
            return false;
        }
};

class Area :public Object{
};

class Building : public Object{
    Cell location;
};
class Map{
    private:
    int width, height;
        std::vector<Cell> cells;
        std::vector<Object> objects;
    public:
        Map(int w, int h){
            this->width = w;
            this->height = h;
            for(int i = 0;i<h;i++){
                for(int j = 0;j<w;j++){
                    cells.push_back(Cell(i,j));
                }
            }
        }
        void draw(){
            std::cout << std::string(width+2,'=') << std::endl;
            for(int i =0; i<height;i++){
                std::cout << '|';
                for(int j= 0;j<width;j++){
                    
                }
                std::cout << '|';
            }
            std::cout << std::string(width+2,'=') << std::endl;

            for(int i =0 ;i<objects.size();i++){
               objects[i].draw();
               objects[i].
            }
        }

};



int main(){
    std::cout << "Hello world!";
    return 0;
}