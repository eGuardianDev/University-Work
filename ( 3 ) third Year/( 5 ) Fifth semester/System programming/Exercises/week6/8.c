#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv[] )
{

  if(argc !=3){
    printf("Not correct args. Usage: %s {cmd1} {cmd2}\n", argv[0]);
    return 1;
  }
  

  if(fork()!=0){
    int status= 0;
    wait(&status);
    if(status !=0) exit(-1);
    execlp(argv[2], argv[2],0);
  }else{
    execlp(argv[1], argv[1],0);
    exit(1);
  }


  return 0;
}
