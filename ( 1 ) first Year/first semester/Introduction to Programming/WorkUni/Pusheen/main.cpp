#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

// void drawSaw(int startY, int toothSize, int nTeeth)
// {
//     for(int i = 0; i < nTeeth; ++i)
//     {
//         sdlw::drawLine(2*i*toothSize,0+startY,(2*i+1)*toothSize,toothSize+startY);    
//         sdlw::drawLine((2*i+1)*toothSize,toothSize+startY,2*(i+1)*toothSize,0+startY);        
//     }

//     sdlw::drawLine(0,0+startY,2*nTeeth*toothSize,0+startY);

// }
struct Points
{
     int x;
     int y;
};

Points drawSinus(int x0, int y0, double freq, double ampl, int number, double prec, int rot ,int way, int startFrom,int endTo)
{
    int x =0;
    int y =0;
    for(double j =0; j<number;j++){

        double nFreq = freq-(j/90);
        double nAmp = ampl-j;

        for(double i = startFrom; i < endTo; i+= prec)
        {
            sdlw::drawPixel(x0 +(j+ i* nFreq) *way, y0+ sin((rot*i)*3.14/180)* nAmp);
        }
        if(j == 0){
            x = x0+endTo * nFreq;
            y = y0 + sin((rot*endTo)*3.14/100*nAmp);
        }
    }
    return {x,y};
}

Points DrawCircle(int x, int y, int radius, int angle, int rotation, int thickness, double precision){

    int endX;
    int endY;

    for(int i =0;i<thickness;i++){

        for(double circleAngle = precision +rotation; circleAngle <= angle + rotation; circleAngle += precision){

            double xPoint =cos(circleAngle*3.14 /180) *(radius-i);
            double yPoint =sin(circleAngle* 3.14/ 180) * (radius-i);
            endX = x+xPoint;
            endY = y+yPoint;
        /// std::cout <<xPoint;
            sdlw::drawPixel(x+ (int)xPoint,y+ (int)yPoint);
        }
    }
    return {endX, endY};
}

Points DrawLine(int x, int y,int xEnd, int yEnd, int thickness){

    if(yEnd>y || yEnd <y){
        for(int i =0;i<thickness;i++){
            sdlw::drawLine(x-i,y,xEnd-i,yEnd);
        }
    }else{
        for(int i =0;i<thickness;i++){
            sdlw::drawLine(x,y-i,xEnd,yEnd-i);
        }
    }
    return {xEnd,yEnd};
}

int main()
{
    //sdlw::setColor(255,255,255);

    //drawSaw(0,40,5);
    //drawSaw(100,20,10);
    //drawSaw(170,40,5);

    // drawSinus(0,100,1,30);
   // sdlw::Hello();
    sdlw::setColor(230,230,230); 
    sdlw::drawFillRect(0,0,500,500);
    sdlw::setColor(80,46,16); 


        sdlw::drawPixel(10,10);
    Points end ;
    
    
      end =DrawCircle(200,200,75,50,120,5,0.1);
      end =DrawCircle(end.x+300-5,end.y,300,25,180,5,0.1);

    
    //ear1
    end = drawSinus(end.x-2,end.y,.25,35,5,0.1,-1,1,0,180);
    //head
    end = DrawLine(end.x-3,end.y, end.x+25+3,end.y,5);
    //ear2

    Points tempend;
    tempend = drawSinus(end.x,end.y,.25,35,5,0.1,-1,1,0,180);
    Points endOfEar2 = tempend;
    //butt
    end = DrawCircle(tempend.x+35,tempend.y+90+17,117,147-60,-110,5,0.1);


    sdlw::setColor(92,83,74); 
    end = DrawCircle(tempend.x+35,tempend.y+90+17,117+14,12,-22,20,0.1);
    
    end = DrawCircle(tempend.x+35+35+4,tempend.y+90+45,117+14, 10 ,-43,15,0.1);

    sdlw::setColor(80,46,16); 
    end = DrawCircle(tempend.x+35,tempend.y+90+17,117,147-60,-110,5,0.1);


    end = DrawCircle(end.x,end.y-32, 35,80,10,5,0.5);

    DrawCircle(end.x+41,end.y-16, 13,180,180+10,5,0.5);

    sdlw::setColor(92,83,74); 
    DrawCircle(end.x+41,end.y-14, 13-3,180,180+10,9,0.5);
    sdlw::setColor(80,46,16); 

    end = DrawCircle(end.x,end.y-25, 55,70,10,5,0.5);

    end = DrawCircle(tempend.x+35,tempend.y+90+17,117,62-20+5,-5-110+75+30,5,0.1);
    std::cout <<end.x <<" " << end.y;
    //belly
   // end = DrawLine(end.x+2,end.y+5,end.x-200 -35,end.y+5,5);

    //spots on back

    sdlw::setColor(92,83,74); 
    DrawCircle(endOfEar2.x+30,endOfEar2.y-10,20,160,10,20,0.1);
    DrawCircle(endOfEar2.x+80,endOfEar2.y,  20,160,30,20,0.1);

    sdlw::setColor(80,46,16); 

    //eyes
    sdlw::drawFillCircle(175+10,110,7);
    sdlw::drawFillCircle(175+70,110,7);

    //mouth 
    int tem_x = 30;
    DrawLine(175 + 40, 78+tem_x, 175+40, 85+tem_x,3);
    drawSinus(175+40,85+tem_x,0.05,2.5,2,0.1,1,1,0,180);
    drawSinus(175+40,85+tem_x,0.05,2.5,2,0.1,1,-1,0,180);


    //right wiskers
    drawSinus(175+40+45,80+10+tem_x-10,0.6,10,5,0.1,-1,1,25,90);

    drawSinus(175+40+45,80+10+tem_x,0.35,7,5,0.1,-1,1,35,150);
    

    //left wiskers
    drawSinus(175+40+45-60-40,80+10+tem_x-10,0.6,10,5,0.1,-1,-1,25,80);

    drawSinus(175+40+45-60-40,80+10+tem_x,0.5,7,5,0.1,-1,-1,35,90);


    //397 259
    //leg1
    end = DrawLine(397+5,259,397+5,259+10,5);
    end = DrawCircle(end.x-7,end.y,7,180,0,5,0.5);
    end = DrawLine(end.x,end.y, end.x,end.y-5,5);
    //leg2
    end = DrawLine(end.x,end.y,end.x-50,end.y,5);

    end = DrawLine(end.x,end.y-4, end.x,end.y+5,5);
    end = DrawCircle(end.x-7,end.y,7,180,0,5,0.5);
    end = DrawLine(end.x,end.y, end.x,end.y-5,5);

    //leg3
    end = DrawLine(end.x,end.y,end.x-95,end.y,5);

    end = DrawLine(end.x,end.y-4, end.x,end.y+5,5);
    end = DrawCircle(end.x-7,end.y,7,180,0,5,0.5);
    end = DrawLine(end.x,end.y, end.x,end.y-5,5);

    //leg4
    end = DrawLine(end.x,end.y,end.x-50,end.y,5);

    end = DrawLine(end.x,end.y-4, end.x,end.y+5,5);
    end = DrawCircle(end.x-7,end.y,7,180,0,5,0.5);
    end = DrawLine(end.x,end.y, end.x,end.y-10,5);

    sdlw::updateGraphics();
   //std::cout<< end.x << " " << end.y <<" "<< end.x+200;
    std::cin.get();

}