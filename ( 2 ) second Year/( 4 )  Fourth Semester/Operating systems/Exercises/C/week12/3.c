#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  
  if(argc!=2){
    printf("error");
    exit(1);
  }

  int fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND | O_EXCL  ,0633);
  char buff[255];
  int red =read(0,buff,255);
  
  int i =0;
  while(i<red){
    if(buff[i] == '\t'){
      write(fd,">>>",3);
    }else{
      write(fd,&buff[i],1);
    }
    i++;
  }
  
  close(fd);
  printf("done");


}
