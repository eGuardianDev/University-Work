#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv[] )
{
  fork();
  fork();
  fork();


  wait(NULL);
  printf("mine: %i, parent: %i\n", getpid(), getppid());
}
