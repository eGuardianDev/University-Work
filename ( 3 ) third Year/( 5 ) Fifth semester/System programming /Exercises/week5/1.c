#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[] )
{
  if(argc != 2){
    printf("Not enought arguments. Usage: %s {file}\n", argv[0]);
    return 1;
  }

  execlp("grep", "grep", "int", argv[1], 0);


}
