#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv[] )
{

  if(argc <3){
    printf("Invalid usage. Usage %s {cmd1} {cmd2} {args}",argv[0]);
    return 1;
  }

  int pd[2]; // 1 is write, 0 is read 
  
  pipe(pd);
  if(fork()){
    close(1);
    dup(pd[1]);
    close(pd[0]);
    close(pd[1]);
    execlp(argv[1], argv[1], 0);
  }else{
    close(0);
    dup(pd[0]);
    close(pd[0]);
    close(pd[1]);
    execvp(argv[2], &argv[2]);
  }
  return 0;
}
