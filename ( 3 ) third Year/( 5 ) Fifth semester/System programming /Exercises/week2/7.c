

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

  if(argc != 4){
    printf("Not enought arguments. Usage %s {start} {end} {file}\n", argv[0]);
    return 1;
  }

  int i = 0;
  int fd = open(argv[3], O_RDONLY);
  

  int start = atoi(argv[1]);
  if(start <=0){
    printf("Cannot be less than 0 start");
    return 3;
  }
  int end   = atoi(argv[2]);
 int final = end;
 int count = start;
  if(end < start){
    printf("Cannot the start be after the end\n");
    return 2;
  }

  int size =0;
  char buff[255];

  int flag = 0;
  while( (size = read(fd, buff, 255)) != 0){
    int i =0;
    for(;i<size;++i){
      if(count >0){
        count--;
      }else{
        if(final > 0){
          if(buff[i] == '\n'){
            count = start;
            final = end;
            printf("\n");
          }else{
            write(1, &buff[i],1);
            final--;
          }
        }else{
          if(buff[i] == '\n'){
            count = start;
            final = end;
            printf("\n");
          }
        }
      }
    }
  } 
  close(fd);
  return 0;
}
