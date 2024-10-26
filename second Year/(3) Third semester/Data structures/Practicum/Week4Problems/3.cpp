#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>     /* abs */

bool dir(int a){
    return (a >= 0);
}
void print( std::stack<int>);
// std::stack<int> Stackusage(std::stack<int>& input){

//     std::stack<int> temp_stack;
//     while(!input.empty()){
//         int first = input.top();  //1
//         input.pop();
        
//         if(input.empty()){
        
//         }


//     }
//     // return final_stack;
// }

std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
    

    std::stack<int> st;
    st.push(asteroids.back());
    asteroids.pop_back();

    while(!asteroids.empty())
    {
        int current = asteroids.back();
        if( current < 0 && 0 < st.top() ){
            if(-current < st.top()){
                asteroids.pop_back();
            }else if(-current > st.top()){
                st.pop();
                st.push(current);
                asteroids.pop_back();
            }else{
                asteroids.pop_back();
            }
        }else{
            asteroids.pop_back();
            st.push(current);
        }
    }


    print(st);
    
    return asteroids;
}
 void print(std::stack<int> st)
{
    while(!st.empty()){
        std::cout <<st.top() << " ";
        st.pop();
    }
    std::cout << "\n";
}
 void print(std::vector<int> st)
{
    while(!st.empty()){
        std::cout <<st[st.size()-1] << " ";
        st.pop_back();
    }
    std::cout << "\n";
}
int main()
{
   
    int n = 2;
    int temp =0;
    std::cin >> n;
    std::vector<int> a;
    std::stack<int> b;
    for(int i =0 ;i<n;i++){
        std::cin >> temp;
        // b.push(temp);
        a.push_back(temp);
    }
    std::vector<int> c = asteroidCollision(a);
    print(c);
    

    return 0;
}