#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *args[]){





  for(int i =0;i<10;++i){
    write(1, "EXAMPLE", 7);
  }

  
  char str[32];
  for(int i =0;i<10;++i){
   // write(1, "EXAMPLE", 7);
    sprintf(str, "i=%d\n",i);
    write(1,str, strlen(str));
  }
  for(int i =0;i<10;++i){
    write(1, "HELLO", 5);
  }
  return 0;
}
