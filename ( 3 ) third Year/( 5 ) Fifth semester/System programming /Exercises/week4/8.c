#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){


  if(argc !=2){
    printf("Invalid usage. Usage: %s {file1}", argv[0]);
    return 1;
  }


  int error2 = dup(2);
  int out1 = dup(1);


  close(0);
  int fd1 = open(argv[1], O_RDONLY );
  
  close(1);
  dup(error2);
  close(2);
  dup(out1);
  if( fd1 == -1  ){
    printf("Error openning file");
    return 2;
  }


  char buff[255];
  int red =0 ;
  while ( (red = read(0, buff,255)) !=0){
    write(1, buff,red);
  }

  close(fd1);

  return 0;
}
