#include <iostream>
#include <vector>



std::vector<int> merge(std::vector<int> first, std::vector<int> second){
    std::vector<int> res(0) ;
    
    int index1 =0;
    int index2 =0;
    while(res.size() != first.size() + second.size()){
        if(first.size() >0 && index1 < first.size()){
            if(second.size() >0 && index2 < second.size()){
                if(first[index1] > second[index2]){
                    res.push_back(second[index2++]);
                }else{
                    res.push_back(first[index1++]);
                }
            }else{
                res.push_back(first[index1++]);
            }
        }else{
            res.push_back(second[index2++]);
        }
    }
    return res;
}


std::vector<int> mergeSort(std::vector<int> vector, int start , int end){
    if(start == end){ return std::vector<int> {vector[start]};}
    if(start > end) return std::vector<int>(0);
    int l = start;
    int r = end;
    int mid = start+(end-start)/2;


    return merge(mergeSort(vector, l, mid),mergeSort(vector,mid+1,r));

}

std::vector<int>mergeSort(std::vector<int> vector){
    return mergeSort(vector, 0, vector.size()-1);
}


void print(std::vector<int> res){
    for(int i =0;i<res.size();++i){
        std::cout <<res[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    std::vector<int> vec = {3,4,5,1,2};

    auto res =(mergeSort(vec));
    print(res);
    


    return 0;
}