#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){

  for(int i =0;i<10;++i){
    write(1, "EXAMPLE", 7);
  }

  return 0;
}
