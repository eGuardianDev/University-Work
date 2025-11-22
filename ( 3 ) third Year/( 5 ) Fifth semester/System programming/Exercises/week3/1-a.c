
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char * argv[]){

  int cr = open("fff", O_CREAT, 0664);
  close(cr);

  int fd1 = open("fff", O_RDONLY);
  int fd2 = open("fff", O_WRONLY);
  int fd3 = open("fff", O_RDWR);
  

  // A)
  
  char* buff[255];
  //1.
  write(fd2, "Hello World", 11);
  //2.
  read(fd3, buff,6);
  write(1,buff,6);
  //3.
  read(fd1,buff,5);
  write(1,buff,5);
  //4.
  write(fd3,"chill",5);
  //5.
  write(fd2,"!!!",3);
  //6
  read(fd1,buff,9);
  write(1,buff,9);

  return 0;
}
