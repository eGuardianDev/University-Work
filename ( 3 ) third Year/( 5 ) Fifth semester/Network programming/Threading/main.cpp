#include <bits/stdc++.h>
using namespace std;

// Function to be run by the thread
void func() {
    cout << "Hello from the thread!" << endl;
}

int main() {
    
    // Create a thread that runs 
    // the function func
    thread t(func);
    
    // Main thread waits for 't' to finish
    t.detach();  
    cout << "Main thread finished.";
    return 0;
}
