#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()

void main (int argc, char *argv[]){
  if(argc != 3){
    printf("invalid count of args");
   exit(1);
  }
  
  int id = fork();

  if(id==0) {
    exit(execlp(argv[1],argv[1],0)); // if this is not exited the program will continue
  }

  int status;
  wait(&status);

  if(status){

    id = fork();

    if(id==0) {
      exit(execlp(argv[2], argv[2],0)); // if this is not exited the program will continue
    }

    status;
    wait(&status);

    if(status){
      printf("fail\n");
      exit(2);
    }
  }
  printf("all good\n");
}
