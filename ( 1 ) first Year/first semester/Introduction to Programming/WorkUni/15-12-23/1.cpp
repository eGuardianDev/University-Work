#include <iostream>
using namespace std;

int rows,collums;
void FillGaps(int **& arr, int i, int j);

void line(char a , int size){
    for(int i = 0;i <size; i++){
        cout << a;
    }
}

void displayMatrix(int ** arr){

    for(int i =0; i< rows ;i++){
        line('-',collums*2+1); cout << endl;
        int* array = arr[i];
        for(int j= 0;j<collums;j++){
            cout<< "|" << array[j];
        }
        cout << "|"<< endl ;
    }
        line('-',collums*2+1); cout << endl;
    

}
void upscaleMatrix(int **& arr){

    int newRows = rows*2+1;
    int newCollums = collums*2+1;
    int ** newArr = new int* [rows*2+1];
    int indexY = 0;
    rows = newRows; collums = newCollums;
    for(int i =0;i<newRows;i++){
        newArr[i] = new int[newCollums];
        if(i%2 != 0){
            int indexX = 0;
            for(int j =0;j<newCollums; j++){
                if(j%2 !=0){
                    newArr[i][j] = arr[indexY][indexX];
                    indexX++;
                   // FillGaps(newArr,i-1,j);
                  FillGaps(newArr,i+1,j); //matrix isnt generated, to do...
                    // FillGaps(newArr,i,j-1);
                    // FillGaps(newArr,i,j+1);
                }
            } 
            indexY++;
        }
    }
    arr = newArr;
}
void FillGaps(int ** & arr, int i, int j ){

        if( i < 0 || i == rows) return;
        if (j <0 || j == collums) return;       


        int devision = 4;
        int x0;
        if( i -1 < 0 ){
            x0 = 0;
            devision--;
        }else x0 = arr[i-1][j];
        
        int x1;
        cout << " index  i  + " << i << " and " << i + 1 << " rows " << rows << endl;  
        if( i + 1 >= rows ){
            x1 = 0;
            devision--;
        }else x1 = arr[i + 1][j];
        
        
        int y0;
        if( j - 1 <0 ){
            y0 = 0;
            devision--;
        }else y0 = arr[i][j-1];
        
        
        int y1;
        if( i + 1 == collums ){
            y1 = 0;
            devision--;
        }else y1 = arr[i][j+1];
        
        
        int val = x0 + x1 + y0 + y1;
        
        arr[i][j] =val/devision;
    }


int main(){
    cin >> rows >> collums;
    
    int ** arr = new int* [rows];
    
    for(int i =0; i <rows; i++){
        arr[i] = new int[collums];
        for(int j = 0;j<collums;j++){
            cin >> arr[i][j];
        }
    }
    
    displayMatrix(arr);


    upscaleMatrix(arr);
  //  FillGaps(arr);
    displayMatrix(arr);
    cout << arr[rows-1][0];
    // upscaleMatrix(arr);
    // displayMatrix(arr);

    return 0;
}