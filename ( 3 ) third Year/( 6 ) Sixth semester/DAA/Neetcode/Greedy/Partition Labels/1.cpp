

#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> res;
    
    
    int i =0;
    unordered_map<int, int> maps;

    vector<bool> visited(s.size(),false);

    for(int i =0;i<s.size();++i){
        maps[s[i]] = i;
    }



    
    for(int i =0;i<s.size();++i){

        if(visited[i]) continue;
        
        int l = i;
        int r = maps[s[l]];

        int result = 0;
        bool flag = false;
        while(l<=r){
            visited[l] = true;
            r = max(maps[s[l]], r);
            result++;
            l++;
        }
        res.push_back(result);

    }

    return res;

}


int main(){

    auto res = partitionLabels("xyxxyzbzbbisl");


    cout << "[ ";
    for(auto a : res){
        cout<< a << " ";
    }
    cout << "]" << endl;




    return 0;
}