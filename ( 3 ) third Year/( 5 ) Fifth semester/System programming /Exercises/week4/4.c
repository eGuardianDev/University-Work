#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *args[]){


  if(argc !=2){
    printf("Invalid usage. Usage: %s {file}", args[0]);
    return 1;
  }


  int fd = open(args[1], O_CREAT | O_WRONLY, 777);

  close(1);

  dup(fd);


  for(int i =0;i<10;++i){
    write(1, "EXAMPLE", 7);
  }



  return 0;
}
