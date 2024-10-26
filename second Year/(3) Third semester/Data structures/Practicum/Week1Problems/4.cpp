#include <exception>
#include <iostream>
#include <type_traits>
#include <vector>


template<class T>
void Display(std::vector<T> data){
    for(T d: data)std::cout << d << " ";
    std::cout<<std::endl;
    return;
}

void DisplayVartiations(std::vector<int> nums, std::vector<int> toDisplay,int index, int current_Sum) {
    if(current_Sum ==0){
        Display(toDisplay);
        return;
    }
    
    for(int i = index; i >=0; i--){
        if(toDisplay.size() > 0 && toDisplay.back() < nums[i]) continue;
        current_Sum-=nums[i];
        if(current_Sum < 0){
            current_Sum+=nums[i];
            continue;
        }
        toDisplay.push_back(nums[i]);
        DisplayVartiations(nums, toDisplay, index, current_Sum);
        current_Sum+=nums[i];
        toDisplay.pop_back();
        
    }


}


void DisplayVariations(std::vector<int> nums, int sum)
{
    DisplayVartiations(nums, std::vector<int>(), nums.size()-1, sum);
}

int main(){

    int size, sum;
    std::vector<int> nums;
    
    std::cin >> sum >>size;
    int temp = 0;
    for(int i =0;i<size;i++){
        std::cin >> temp;
        nums.push_back(temp);
    }
    DisplayVariations(nums, sum);
    
    return 0;   
}