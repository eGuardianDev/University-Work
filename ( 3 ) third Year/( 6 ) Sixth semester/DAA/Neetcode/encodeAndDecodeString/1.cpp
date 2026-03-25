

#include "iostream"
#include "vector"

using namespace std;

string encode(vector<string>& strs) { // A[1...n]
    // m is the sum of lengths
    // n is the number of strings
    // m + n
    string result = "";
    for(int i =0;i<strs.size();++i){ // O(n)
        result += "#"; // 1
        
        int count = strs[i].size(); // 1

        if(count < 10){ // 1
            result +='0'; //1
        }else{
            result += count/10 + '0';
        }
        result += (count% 10 + '0'); //1 

        result += strs[i]; // 1
    }

    return result;
}


vector<string> decode(string s) {
    string data;

    vector<string> result;
    int n = s.size();
    int index =0;
    char c ;
    int count = 0;

    while(index < n){
        data = "";
        c = s[index];
        if(c == '#'){
            count = 0;
            index++;
            c = s[index];
            count += (c - '0') * 10;
            index++;
            c = s[index];
            count += c -'0';
            index++;
        }
        // cout << count << endl;
        int start = 0;
        while(start < count){
            c = s[index];
            data += c;
            ++start;
            ++index;
        }
        result.push_back(data);
    }


    return result;
}

int main(){

    std::vector<string> input;

    // input.push_back("doge");
    // input.push_back("reallyLong");
    // input.push_back("cat");
    input.push_back("");

    string data = encode(input);


    std::vector<string> decoded = decode(data);

    cout << "decoding...." << endl;
    for(auto s: decoded){
        std::cout << s <<std::endl;
    }


    cout <<data << endl;


    return 0;
}