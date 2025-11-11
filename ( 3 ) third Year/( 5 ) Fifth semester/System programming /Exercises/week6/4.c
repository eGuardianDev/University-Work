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

  int fd1 = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);

  if(fork() == 0){
    write(fd1, "hello2", 6);
  }else{
    write(fd1, "hello1", 6);
  }



  return 0;
}
