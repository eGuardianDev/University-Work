  
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

  if(argc !=3){
    printf("Not enought args. Usage %s {lines} {file}", argv[0]);
    return 1;
  
  }

  int flag = atoi(argv[1]);
  int fd = open(argv[2], O_RDONLY);

  if(fd == -1){
    printf("Couldn't open file.");
    return 2;
  }

  char buff[255];
  int red=0;
  while(flag >0){
    red = read(fd,buff,1);
    if(red == 1){
      if(buff[0] == '\n'){
        flag--;
        continue;
      }
    }else{
      printf("Not enought lines in file");
      return 3;
    }
  }

  while( (red= read(fd,buff,255)) !=0){
    write(1,buff,red);
  }
  close(fd);

}
