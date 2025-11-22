
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char * argv[]){

  int cr = open("fff", O_CREAT, 0664);
  close(cr);

  int fd1 = open("fff", O_RDONLY);
  int fd2 = open("fff", O_WRONLY);
  int fd3 = open("fff", O_RDWR);
  

  // B)
  
  char* buff[255];
  //1.
  write(fd3, "Hello", 5);
  //2.
  write(fd2, "worlds", 6);
  //3.
  read(fd1, buff, 6);
  write(1, buff, 6);
  //4.
  close(fd2);
  //5.
  write(fd3, "oops", 4);
  //6.
  read(fd1, buff, 6);
  write(1, buff, 6);

  return 0;
}
