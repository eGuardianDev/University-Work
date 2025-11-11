#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){


  if(argc !=3){
    printf("Invalid usage. Usage: %s {file1} {file2}", argv[0]);
    return 1;
  }




  close(0);
  int fd1 = open(argv[1], O_RDONLY );
  close(1);
  int fd2 = open(argv[2], O_CREAT | O_WRONLY, 0777);
  if( fd1 == -1 || fd2 == -1 ){
    printf("Error openning file");
    return 2;
  }


  char buff[255];
  int red =0 ;
  while ( (red = read(0, buff,255)) !=0){
    write(1, buff,red);
  }

  close(fd1);
  close(fd2);

  return 0;
}
