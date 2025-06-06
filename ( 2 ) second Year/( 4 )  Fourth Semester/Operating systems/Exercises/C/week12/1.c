#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  if(argc != 3){
    printf("invalid count of args");
   exit(1);
  }

  int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0733);
  int source = open(argv[1], O_RDONLY);

  int n =0;
  int buff[32];
  while( (n=read(source,buff,32 ) ) >0){
    write(dest, buff,n);
  }

  close(dest);
  close(source);
}
