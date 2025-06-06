#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()

void main (int argc, char *argv[]){
  if(argc <2){
    printf("invalid count of args");
    exit(1);
  }
  
  int errors = 0;
  int complete =0;

  for(int i=1;i<argc;++i){
    if(fork()){
      int status;
      wait(&status);
      if(status) errors++;
      else complete++;
    }else{
      exit(execlp(argv[i],argv[i],0));
    }
  }
  
  printf("Number of complete: %d\nNumber of errors: %d\n", complete, errors);

} 
