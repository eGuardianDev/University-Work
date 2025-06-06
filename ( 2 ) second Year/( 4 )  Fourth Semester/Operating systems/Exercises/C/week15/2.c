#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()

void main (int argc, char *argv[]){
  if(argc != 4){
    printf("invalid count of args");
    exit(1);
  }
  
  if(fork()){
    int status;
    wait(&status);
    printf("Status of grep is: %d\n",status);
  }else{
    exit(execlp("grep", "grep", "int", argv[1], 0));
  }

  if(fork()){
    int status;
    wait(&status);
    printf("status of command is: %d\n", status);
  }else{
    exit(execvp(argv[2],&argv[2]));
  }
} 
