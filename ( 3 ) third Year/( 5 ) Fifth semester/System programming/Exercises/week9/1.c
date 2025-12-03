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

  int fd = open("testFile", O_RDWR | O_CREAT | O_TRUNC, 0664);

  int i = 0;
  write(fd,&i,sizeof(int));

  char buff[255];
  int pid = fork();

  if(pid){
    while(i <=100){
      lseek(fd, 0, SEEK_SET);
      read(fd, &i, sizeof(int));
      ++i;
      printf("p: %d\n", i);
      lseek(fd,0,SEEK_SET);
      write(fd, &i,sizeof(int));
    }
  }else{
    while(i <=200){
      lseek(fd, 0, SEEK_SET);
      read(fd, &i, sizeof(int));
      i+=2;
      printf("\t\t\t c:%d\n", i);
      lseek(fd,0,SEEK_SET);
      write(fd, &i,sizeof(int));
    }
  }

  return 0;
}
