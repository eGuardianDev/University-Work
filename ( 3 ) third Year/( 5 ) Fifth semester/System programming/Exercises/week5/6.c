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

  int fd = open(argv[1], O_WRONLY | O_TRUNC | O_EXCL | O_CREAT, 0644);
  
  if(fd == -1){
    printf("Failed to create file\n");
    return 1;
  }

  //1.
  /*int pid = fork();
  int status;
  if(pid ==0){
    wait(&status);
    
    pid = fork();

    if(pid == 0){
      wait(&status);
      close(fd);
    }else{
      write(fd, "HELLO",5);
    }
  }else 
  {
      write(fd, "HELLO",5);
  }*/
  //2.
  /*
  int fd2 = open(argv[1], O_WRONLY);
  int pid = fork();
  int status;
  if(pid ==0){
    wait(&status);
    
    pid = fork();

    if(pid == 0){
      wait(&status);
      close(fd);
      close(fd2);
    }else{
      write(fd2, "HELLO",5);
    }
  }else 
  {
      write(fd, "HELLO",5);
  }*/

  //3.
  int fd2 = dup(fd);
  int pid = fork();
  int status;
  if(pid ==0){
    wait(&status);
    
    pid = fork();

    if(pid == 0){
      wait(&status);
      close(fd);
      close(fd2);
    }else{
      write(fd2, "HELLO",5);
    }
  }else 
  {
      write(fd, "HELLO",5);
  }

  return 0;
}
