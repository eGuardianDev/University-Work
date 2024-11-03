

#include <iostream>

struct rect {
    int x,y; //width and length 
};

class Land{

    private:
    rect *Rectangles;
    int numberOfRect= 0;
    
    void expand(){
        rect *temp = new rect[this->numberOfRect+1];
        for(int i=0;i<this->numberOfRect;i++){
            temp[i] = Rectangles[i];
        }
        this->numberOfRect++;
        this->Rectangles = temp;
    }
    void copy(Land& l){
        int numOfLTriang = l.getRectNum();
        //delete [] this->Rectangles;
        this->Rectangles = new rect[numOfLTriang];
        for (int i = 0; i < numOfLTriang; i++)
        {
            this->Rectangles[i] = l.Rectangles[i];
        }
        this->numberOfRect = numOfLTriang;
        
    }

    public:
    int getRectNum(){
        return this->numberOfRect;
    }
    void addRectangle(rect& _rect){
        expand();
        Rectangles[numberOfRect-1] = _rect;
    }

    Land(){
        Rectangles = new rect[0];
        numberOfRect = 0;
    } 

    Land(Land& l){
        if(this != &l){
            copy(l);
        }
    }

    ~Land(){
        delete [] Rectangles;
    }


    Land operator+(rect& _rect){
        Land l = *this;
        l.addRectangle(_rect);
        return l;
    }

    Land& operator+=(rect& _rect){
        this->addRectangle(_rect);
        return *this;
    }
    int mod(int val){
        if(val <0) return -val;
        return val; 
    }


    int Fence(){

        if(numberOfRect == 0) return 0;
        if(numberOfRect == 1){
            return Rectangles[0].x* 2 +Rectangles[0].y;
        }
        int fence = Rectangles[0].y;
        int lastTrig;
        for(int i = 0; i <numberOfRect;i++){
            fence += Rectangles[i].x * 2;
        }
        for(int i = 0; i< numberOfRect-1;i++){
            
            fence+= mod(Rectangles[i].y-Rectangles[i+1].y);
            lastTrig = i;
        }
        fence+= Rectangles[lastTrig+1].y;
        return fence;
    }

    int Area(){
        int area = 0;
        for(int i =0 ;i < numberOfRect;i++){
            rect current = Rectangles[i];
            area += current.x * current.y;
        }
        return area;
    }

};

int main(){

    Land l;
    rect r; r.x = 1, r.y = 2;    //  2
    rect r2; r2.x = 4; r2.y =5; // 20
    rect r3; r3.x = 3; r3.y =8; // 24

    l+=r;
    l+=r2; 
    l+=r3;
    std::cout << l.Fence() << '\n';
    std::cout << l.Area();

    return 0;
}