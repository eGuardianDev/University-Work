#include <iostream>

using namespace std;
void myfunc(string*& val)
{
    val = new string("4");
    // Do stuff to the string pointer
}


void myfunc2(string* const& val)
{
    *val = "3";
    // Do stuff to the string pointer
}

int main()
// sometime later 
{
    // ...
    string s = "1";
    string* ps = &s;
    std::cout << s;

    myfunc( ps);   // OK because ps is not a temporary
    std::cout << s;
    myfunc2( &s);  // OK because the parameter is a const&
    std::cout << s;
    // ...

    return 0;
}