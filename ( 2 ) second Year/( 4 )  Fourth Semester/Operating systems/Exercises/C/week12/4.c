#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  
  if(argc!=3){
    printf("error");
    exit(1);
  }
  int fd = open(argv[1], O_RDONLY);
  int dest= open(argv[2], O_WRONLY | O_APPEND);
  int n =0;
  char buff;

  int count =0;
  while( read(fd,&buff,1)){
    if(count <3){
      
      write(dest, &buff, 1);
     count++;
    }
    write(1,&buff,1);
    if(buff == '\n'){
      count =0;
    }
  }
  close(dest);
  close(fd);
}
