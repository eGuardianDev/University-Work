#include <iostream>

const int maxx = 5;

long long data[maxx];
int main(){


    int n =0 ;
    std::cin >> n;

    int i =0;
    for(i =0;i<n;++i){
        std::cin >> data[i];
    }


    for(i = 0;i<n;++i){
        int count =0 ;
        
        while(data[i]){
            
            int res = data[i] %  2;
            if(res ) ++count;
            data[i] /=2;
        }
        data[i] =  count;
        
    }


    for( i=0 ;i<n;++i){
        std::cout << data[i] << std::endl;
    }




    return 0;
}