#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){


  if(argc !=2){
    printf("Invalid usage. Usage: %s {file}", argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_CREAT | O_WRONLY, 0777);

  if(fd == -1){
    printf("Error openning file");
    return 2;
  }

  for(int i =0;i<10;++i){
    write(1, "EXAMPLE", 7);
  }
  int dup1 = dup(1);

  printf("\n");
  close(1);
  dup(fd);
  


  char str[32];
  for(int i =0;i<10;++i){
   // write(1, "EXAMPLE", 7);
    sprintf(str, "i=%d\n",i);
    write(1,str, strlen(str));
  }
  close(1);
  dup(dup1);


  for(int i =0;i<10;++i){
    write(1, "HELLO", 5);
  }
  return 0;
}
