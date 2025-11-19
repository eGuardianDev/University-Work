#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>


// char* splitString(char arg[]){

// }

// int clearMem(char** data){
// }

int main (int argc, char *argv[] )
{

  char ps1[] = "Hello world: ";
  int const INPUTBUFFERSIZE = 255;

  char inputBuff[INPUTBUFFERSIZE];

  char input[] = "cat";

    /*
    //input
    write(1,ps1,strlen(ps1));
    int red = read(0,inputBuff, INPUTBUFFERSIZE);

    // if EOF is passed as argument
    if(inputBuff[0]=='\0') {
      write(1, '\n',1);
      return 0;
    }
    */
    
    // start spliting program
    int pid = fork();     
    if(pid){
      int status, childpid;
      childpid = wait(&status);
      printf("child status: %d\n", status);
    }else{
      execlp(input, input, 0);
      return 1;
    }



  return 0;
}
