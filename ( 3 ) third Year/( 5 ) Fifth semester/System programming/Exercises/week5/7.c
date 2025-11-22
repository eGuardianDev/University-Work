#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (int argc, char *argv[] )
{
  if(argc != 2){
    printf("Not enought arguments. Usage: %s {file}\n", argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_WRONLY | O_TRUNC | O_EXCL | O_CREAT, 0644);
  
  if(fd == -1){
    printf("Failed to create file\n");
    return 1;
  }

  int pid = fork();

  if(pid ==0){
    write(fd, "HELLO",5);
  }else{
    int status;
    wait(&status);
    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
      printf("Failed to open file\n");
      return 2;
    }
    char buff[255];
    int red = read(fd1, buff,255);

    printf("Reading %i chars\n",red);
    if(red >0){
      for(int i =0;i<red;++i){
        write(1,&buff[i],1);
        if( i != red-1){
          write(1," ", 1);
        }
      }
    }else{
      printf("Empty file?");
    }


  }

  return 0;
}
