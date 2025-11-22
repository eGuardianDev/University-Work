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
    printf("Not correct args. Usage: %s {file1} {file2}\n", argv[0]);
    return 1;
  }


  int dup_1 = dup(1);
  //int fd1 = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);

  int fd3 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

  int pid = 0;
  if((pid = fork()) == 0){
    close(1);
    int fd2 = dup(fd3); 
  }else{
    wait(NULL);
  }
  
  write(1, "hello3", 6);

  write(fd3, "hello4", 6);

  if(pid == 0){
    close(1);
    int a= dup(dup_1);
  }

  write(1, "good", 4);

  return 0;
}
