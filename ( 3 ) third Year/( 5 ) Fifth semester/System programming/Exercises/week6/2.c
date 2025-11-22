#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[] )
{

  int i = fork();
 

  if(i ==0){
    fork();
  }

  wait(NULL);

  printf("mine: %i, parent: %i\n", getpid(), getppid());


}
