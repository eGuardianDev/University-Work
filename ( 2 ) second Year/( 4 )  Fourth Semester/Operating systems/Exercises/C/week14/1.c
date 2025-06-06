#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  /*if(argc != 3){
    printf("invalid count of args");
   exit(1);
  }*/
  
  int id = fork();

  if(id==0) sleep(2);

  printf("current %d", getpid());
  printf("parrent %d\n", getppid());
  


}
