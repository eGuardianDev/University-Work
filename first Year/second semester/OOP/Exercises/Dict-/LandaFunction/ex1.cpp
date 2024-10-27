#include <iostream>
#include <functional>



using doublefn = std::function<double(double)>;

doublefn squared (doublefn f,int a){

    return [f,a](double x)->double{return f(x)*a;};

}

int main(){

    doublefn f =squared([](double x)->double{return x*x;}, 5);

    std::cout << f(10);
    return 0;

}