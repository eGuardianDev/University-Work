#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){

  if(argc != 2){
    printf("invalid count of args");
   exit(1);
  }
  int n,m;
  scanf("%d %d", &n, &m);
  
  int fd= open(argv[1],O_RDONLY);
  int count =-n+1;
  char ch;
  while(read(fd,&ch,1)){
    if(ch == '\n'){
      count = -n;
    }
    count++;
    if(count >=0 && count <=m){
      write(1,&ch,1);
    }
  }

  close(fd);
}
