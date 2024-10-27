
#include <iostream>
#include "word.h"

int main(){

     char w[21];
     std::cin >> w;
     
    Word word1(w);
     Word word2;

    word2 += word1[1];
     if(word2<word1){
          word2 += word1[0];
     }

     std::cout << word1 << " " << word2 << "\n";
     return 0;
}