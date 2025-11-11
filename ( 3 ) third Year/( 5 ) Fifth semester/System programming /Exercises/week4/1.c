#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){

  int fd = open("File", O_RDONLY);

  int n_fd = dup(fd);

  char buff[255];
  int red;

  red = read(fd, buff, 5);
  write(1, buff, red);

  write(1,"\n",1);

  red = read(n_fd, buff, 5);
  write(1, buff, red);
  write(1,"\n",1);

  
  close (fd);

  
  red = read(n_fd, buff, 5);
  write(1, buff, red);

  write(1,"\n",1);

  close(n_fd);


  return 0;
}
