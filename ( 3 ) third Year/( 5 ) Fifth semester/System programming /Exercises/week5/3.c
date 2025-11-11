#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv[] )
{
  if(argc != 2){
    printf("Not enought arguments. Usage: %s {file}\n", argv[0]);
    return 1;
  }

  int pid = fork();

  if(pid ==0){
    execlp(argv[1], argv[1], NULL);
    return 1;
  }else{
    int status = 1;
    wait(&status);
    if(status == 0){
      printf("%s\n",argv[1]);
    }else{
      printf("Program failed\n");
    }
  }


}
