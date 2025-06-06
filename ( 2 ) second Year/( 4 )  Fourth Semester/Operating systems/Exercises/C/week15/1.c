#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()

void main (int argc, char *argv[]){
  if(argc != 1){
    printf("invalid count of args");
   exit(1);
  }

  int fd = open("abc", O_CREAT | O_WRONLY, 0644);

  int status;
  if(fork() == 0){
    wait(&status);
    if(fork()){
      wait(&status);
      close(fd);
    }else{
      write(fd,"hello",5);
    }
  }else{
      write(fd,"hello",5);
  }
}
