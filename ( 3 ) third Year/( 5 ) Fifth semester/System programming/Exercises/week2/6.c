
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main( int argc, char* argv[]){
  
  if(argc != 3){
    printf("Not enought arguments. Usage %s {number} {file}\n", argv[0]);
   return 1;
  }

  int newLines = atoi(argv[1]);
  int size =0;
  int fd = open(argv[2], O_RDONLY);

  int flagLeave = 0;
  char buff[255];
  while( (size = read(fd, buff, 255)) != 0){
    int i =0;
    if(flagLeave == 1){
      break;
    }
    for(; i<size ;++i){

      if(buff[i] == '\n'){
        --newLines;
      }
      write(1,&buff[i],1);
      if(newLines == 0){
        flagLeave = 1;
        break;
      }
    }
    
  }
  

  return 0;
}
