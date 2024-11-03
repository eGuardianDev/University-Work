#include <iostream>

int main(){
    //init matrix with size n x m
    int n,m;
    std::cin >> n >> m;
    int arr[n][m];
    std::cout << "input data" << std::endl;

    //input matrix
    for(int i =0;i<n;i++){
        for(int j = 0;j <m;j++){
            std::cin>>arr[i][j];
        }
    }
    std::cout << "starting displaying" << std::endl;
    

    int stepsOfX = n;
    int stepsOfY = m-1;

    int indexX =-1;
    int indexY =0;
    int movementX = 1;
    int movementY = 1;
    bool moveX = true;

    while (true)
    {
        if(moveX){
            std::cout << "X: "<< std::endl;
            for(int i =0;i<stepsOfX;i++){

                indexX+=movementX;
                std::cout << arr[indexY][indexX] << " ";
               // std::cout << indexX << ' ';
            }
            std::cout << std::endl;

            movementX = -movementX;
            moveX= false;

            if(stepsOfX > 0){
                stepsOfX--;
            }else{
                break;
            }


        }
        if(!moveX){
            std::cout << "Y: "<< std::endl;
            for(int i =0;i<stepsOfY;i++){

                indexY+=movementY;
                std::cout << arr[indexY][indexX] << " ";
                //std::cout << indexY << ' ';

            }
            std::cout << std::endl;

            movementY = -movementY;


            if(stepsOfY > 0){
                stepsOfY--;
            }else{
                break;
            }

            moveX = true;
        }
    }
    
    



    //display matrix
    // for(int i =0;i<n;i++){
    //     for(int j = 0;j <m;j++){
    //         std::cout << arr[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    return 0;
}