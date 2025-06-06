#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()


void main (int argc, char *argv[]){
  
  if(argc!=2){
    printf("error");
    exit(1);
  }
  int fd = open(argv[1], O_RDONLY);
  if(fd <0){
    printf("not existing file");
    exit(2);
  }

  int n =0;
  char ch;
  
  int bytes=0;
  int words=0;
  int lines=0;

  int charBefore=0;
  while((n = read(fd, &ch,1))){
    bytes++;
    if(ch=='\n'){
        lines++;
      if(charBefore >0) {
        words++;
        charBefore =0;
      }
    }
    else if(ch==' '){
     if(charBefore)words++;
      charBefore= 0;
    }else{
      
    charBefore++;
    }
  }


  printf(argv[1]);
  printf("  B:%d W:%d L:%d",bytes,words,lines);

  close(fd);
}
