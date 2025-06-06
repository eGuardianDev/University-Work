#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  char buff[25];
  int fd = open("test", O_RDONLY);

  read(fd,buff,10);
  int i =0;
    write(1,buff,10);

  printf("\n");

  close (fd);
}
