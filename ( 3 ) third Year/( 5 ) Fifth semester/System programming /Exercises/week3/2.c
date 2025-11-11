#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){

  int r_fd = open("f1", O_RDONLY);
  int w_fd = open("f1", O_WRONLY);

  //1.
  lseek(w_fd,-2, SEEK_END);
  write(w_fd, "wxyz", 4);
  //2.
  lseek(w_fd, 4, SEEK_SET);
  write(w_fd, "12", 2);

  //3.
  char buff[255];
  int red= read(r_fd, buff,16);
  write(1, buff,red);  
  return 0;
}
