#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){

  if(argc <= 1){
    printf("invalid count of args");
   exit(1);
  }

  int fds[argc-1];

  int i=0;
  for(i= 1;i<argc;++i){
    fds[i-1]=open(argv[i],O_RDONLY);
  }
  char buff[512];
  int n =0;

  for(i =0;i<argc-1;++i){
    while( (n=read(fds[i],buff,512 ) ) >0){
      write(0, buff,n);
    }
  }

  for(int i =0;i<argc-1;++i){
    close(fds[i]);
  }
}
