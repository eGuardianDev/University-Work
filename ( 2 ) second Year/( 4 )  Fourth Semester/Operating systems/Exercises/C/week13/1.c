#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  /*if(argc != 3){
    printf("invalid count of args");
   exit(1);
  }*/

  char buff[32];
  int n =0;
  while( (n=read(1,buff,32 ) ) >0){
    write(1, buff,n);
  }
}
