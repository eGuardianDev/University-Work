
#include "node.hpp"
#include <functional>
#include <iterator>

template <typename Type, typename Result>
Result accumulateBTree(
    const Node<Type> *btree,
    const std::function<Result(const Type&)>& transformValueFunc,
    const std::function<Result(const Result&, const Result&)>& accumulateFunc,
    const Result& initialValue
){
    if(!btree) return initialValue;

    Result a = initialValue; 
    a = accumulateFunc(initialValue, transformValueFunc(btree->value));
    
    a+=accumulateBTree(        btree->left,
                            transformValueFunc, 
                            accumulateFunc,
                            initialValue);
    a+=accumulateBTree(        btree->right,
                            transformValueFunc, 
                            accumulateFunc,
                            initialValue);

    return a;
}


int main(){
    Node<int> *btree = new Node<int>(1,
                                new Node<int>(2,
                                                new Node<int>(3),
                                                new Node<int>(4)),
                                new Node<int>(5,
                                                new Node<int>(6),
                                                new Node<int>(7)));
   
    std::function<int(const int&)> squareFn = [] (const int& value) -> int { return value * value; };
   
    std::function<int(const int&, const int&)> sumFn = [] (const int& value1, const int& value2) -> int { return value1 + value2; };

    std::cout << accumulateBTree<int, int>(btree, squareFn, sumFn, 0) << std::endl;

// 1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6 + 7*7
// 140

    return 0;
}