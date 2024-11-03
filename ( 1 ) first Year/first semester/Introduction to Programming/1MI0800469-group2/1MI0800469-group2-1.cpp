#include <iostream>



int main(){
    int rows = 5;
    int collums=10;
    double arr[rows][collums]= {0};

    //input
    for(int i =0;i<rows;i++){
        for(int j=0;j<collums;j++){
            std::cin >> arr[i][j];
        }
    }

    bool flag = true;
    for(int i =0;i<rows;i++){
        for(int j = i+1;j<rows;j++){
            double * first = arr[i];
            double * second = arr[j];
            double k = first[0] / second[0];
            for(int j =1;j<collums;j++){

                if(second[j]*k == first[j]){
                    flag = false;
                }
            }   

        }
        
    }
    if(!flag) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;




    return 0;
}