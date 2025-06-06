#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){

  if(argc != 2){
    printf("invalid count of args");
   exit(1);
  }

  int fd = open(argv[1], O_WRONLY | O_CREAT, 0664);
  if(fd <0){
    printf("Error");
    exit(2);
  }

  char buff[512];
  int n =0;
  while( (n=read(0,buff,512 ) ) >0){
    write(1, buff,n);
    write(fd, buff,n);
  }

  close(fd);
}
