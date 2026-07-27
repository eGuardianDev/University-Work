#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    //edge cases 

    if(tasks.size() == 0) return 0;
    if(tasks.size() == 1) return 1;

    std::sort(tasks.begin(), tasks.end());


    char current = tasks[0];

    std::vector<char> sym;
    std::vector<int> cnt;

    int cnt1= 0;
    for(auto a: tasks){
        if(a == current){
            cnt1++;
        }else{
            sym.push_back(current);
            cnt.push_back(cnt1);
            cnt1 = 1;
            current = a;
        }
    }

    sym.push_back(current);
    cnt.push_back(cnt1);



    
    std::vector<char> res;
    int index =0;
    int cool = n;
    for(int i =0;i< sym.size(); ++i){
        
        index = 0;
        int counter = cnt[i];
        char current = sym[i];
        cool = 0;
        
        while(counter > 0){
            if(res.size() == index){
                if(cool == 0) {
                    res.push_back(current);
                    cool = n;
                    counter--;
                } else {
                    res.push_back(' ');
                    --cool;
                }
                index++;
            }else{
                if(cool ==0){
                    if(res[index] == ' '){
                        res[index] = current;
                        cool = n;
                        counter--;
                    }
                }else{
                    --cool;
                }
                ++index;
            }
        }
    }



    // for(int i =0; i <res.size();++i){
    //     std::cout << res[i] <<"  "  << std::endl;
    // }



    return res.size();
}

int main(){
    
    // std::vector<char> tasks = {'A','C','A', 'B', 'D', 'B'};
    // std::vector<char> tasks = {'A','A','A', 'B', 'B', 'B'};
    std::vector<char> tasks = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
    int n = 2;


    std::cout << leastInterval(tasks, n);

    return 0;
}