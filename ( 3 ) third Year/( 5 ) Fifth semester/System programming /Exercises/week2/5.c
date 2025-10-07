
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char* argv[]){


  int from =0; 

  int lines = 0;
  int words = 0;
  int chars = 0;

  int WordFound = 0;
  int count =0;
  char buff[255];
  

  if(argc >1){
   for(int i =0 ;i<argc-1;++i){
      int fd = open(argv[i+1], O_RDONLY);
   while( (count = read(fd, buff, 255)) != 0 ){
    for(int i =0;i<count;++i){
      switch(buff[i]){
        case ' ':   
            WordFound = 0;
            chars++;
              break;
        case '\n':  
          WordFound =0;
          lines++;
          chars++;
        break;

        default:
          if(WordFound ==0){
            words++;
          }
          WordFound =1;
          chars++;
        break;
      }

    }
  }
    close(fd);
    }
  }
  else{

  
  while( (count = read(from, buff, 255)) != 0 ){
    for(int i =0;i<count;++i){
      switch(buff[i]){
        case ' ':   
            WordFound = 0;
        break;
        case '\n':  
          WordFound =0;
          lines++;
        break;

        default:
          if(WordFound ==0){
            words++;
          }
          WordFound =1;
          chars++;
        break;
      }

    }
  }
  }
  printf("Lines: %d, Words: %d, Chars: %d", lines, words, chars);

  return 0;
}
