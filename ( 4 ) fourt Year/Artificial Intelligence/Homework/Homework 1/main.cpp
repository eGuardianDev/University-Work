

#include <iostream>
#include <vector>
#include <stack>

std::stack<std::vector<int>> result;
void setup(std::vector<int> &stones, int n){

    int size = 2*n +1;
    for(int i =0;i<n;++i){
        stones[i] = 1;
    }

    for(int i =n+1;i<size;++i){
        stones[i] = 2;
    }

}

void print(std::vector<int> stones, int size){
    for(int i =0 ;i<size;++i){
        std::cout << stones[i] << " ";
    }
    std::cout << std::endl;
}


bool correct(std::vector<int> stones){
    int size = stones.size();


    for(int i =0;i<size/2;++i){
        if(stones[i] != 2){
            return false;
        }
    }
    for(int i =size/2+1;i<size;++i){
        if(stones[i] != 1){
            return false;
        }
    }
    return true;
}
void print(std::stack<std::vector<int>> stac){

    std::stack<std::vector<int>> temp;
    
    while(!stac.empty()){
        std::vector<int> val = stac.top();
        temp.push(val);
        stac.pop();
    }

    while(!stac.empty()){
        std::vector<int> val = temp.top();
        for(auto a : val){
            std::cout << a << " ";
        }
        std::cout << std::endl;
        stac.push(val);
        temp.pop();
    }
    
    std::cout << std::endl;
}

bool can_jump(std::vector<int> stones, int index){
    
    if(index <0 || index >= stones.size()) return false;

    if(stones[index] == 2) return false;

    if(stones[index] == 1){
        if(index + 1 < stones.size()){
            if(stones[index+1] == 0){
                return true;
            }else{
                if(stones +2 <stones.size()){
                    if(stones[index+2] == 0){
                        return true;   
                    }
                }
            }
        }
        return false;   
    }else{
        
    }

}

void run(std::vector<int> stones, int size){
    if(correct(stones)){
        print(stones, size);
    }
    
    for(int i =0;i<size;++i){

    }
    
}
int main(){

    printf("Enter size: ");
    int n = 0;
    std::cin >> n;

    if(n <=0){
        printf("Invalid input\n");
        return 1;
    }

    int size = 2*n +1;
    std::cout << "Size is: " << size << std::endl;

    std::vector<int> stones(size,0);

    setup(stones,n);

    print(stones,size);

    return 0;
}