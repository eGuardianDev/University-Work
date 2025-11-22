#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){


  int fd = open("F1", O_CREAT | O_WRONLY, 777);

  close(1);

  dup(fd);


  for(int i =0;i<10;++i){
    write(1, "EXAMPLE", 7);
  }



  return 0;
}
