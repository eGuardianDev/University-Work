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
    exit(execl(argv[1],argv[1], argv[2],0)); // if this is not exited the program will continue
  }

  int status;
  int cpid =wait(&status);
  
  if(status == 0){
    printf("status code: %d\n",status);
    printf("child process id: %d\n", cpid);
  }else{
    printf("program failed\n");
  }

}
