#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()


int strlen_custom(char* argv){
  for(int i=0;i<255;++i){
    if(argv[i] == '\0'){
      return i;
    }
  }
  return -1;
}

void main (int argc, char *argv[]){
  if(argc != 4){
    printf("invalid count of args\n");
    exit(1);
  }

  int fd = open(argv[3], O_WRONLY | O_APPEND );

  if(fd <0){
    fd = open(argv[3], O_CREAT |  O_WRONLY , 0655);
  }
  
  if(fd <0){printf("Critical error\n"); exit(1);}

  if(fork()){
    int status;
    wait(&status);
    if(status == 0){
      write(fd,argv[1],strlen_custom(argv[1]));
    }else{
      printf("Command 1 failed!\n");
    }
    
    if(fork()){
      wait(&status);
    }else{
      exit(execlp(argv[2],argv[2],0));
    }

  }else{
    exit(execlp(argv[1],argv[1],0));
  }


}  
