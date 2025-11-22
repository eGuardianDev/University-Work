#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>




int min(int a, int b){
  return (a>b) ? a : b;
}

int compareString( char* a, char* b){

  int size = strlen(a);
  if(size != strlen(b))
    return 1;

  for(int i =0; i< size;++i){
    if(a[i] > b[i]) return 2;
    if(a[i] < b[i]) return 3;
  }

  return 0;
}



int cleanBuff(char* input){

  int size = strlen(input);
  if(size == 0){
    return 1;
  }

  
  int shifts = 0;

  //remove spaces at end;
  for(int i =size-1; i> 0; --i){
    if(input[i] != ' ' && input[i] != '\t') break;
    ++shifts;
  }

  
  // remove spaces at start;
  for ( int first = 0;first<size;++first){
    if(input[first] == ' ' || input[first] == '\t'){
      for(int i= first;i<size-1;++i){
        input[i] = input[i+1];
      }
      shifts++;
      --first;
    }else break;
  }


  //fix end of string;
  input[size - shifts] = '\0';


  
  return 0;
}

int main (int argc, char *argv[] )
{

  // char ps1[] = "\
  // ┏━━━━━━━━━━┓ \n\
  // ┃Hello bash┃ \n\
  // ┗━━━━━━━━━━┛ \n\
  // >";
  char ps1[] = "┃Hello bash┃ \n>";
  int const INPUTBUFFERSIZE = 255;

  char inputBuff[INPUTBUFFERSIZE];


  while(1){

    //input
    // int pid1= getpid();
    // printf("current %d\n",pid1);
    write(1,ps1,strlen(ps1));
    int red = read(0,inputBuff, INPUTBUFFERSIZE);

    // if EOF is passed as argument
    inputBuff[min(red-1, INPUTBUFFERSIZE-1)] = '\0';

    if(red>0){
      if(inputBuff[red-1] == '\n') inputBuff[red-1] = '\0';
    }
    if(red ==0){
      write(1,"\n",1);
      return 0;
    }

    if(compareString(inputBuff, "bye") == 0){
      printf("Bye!\n");
      return 1;
    }

    // if(red ==0 && inputBuff[0] == '\0') {
    //   write(1, "\n",1);
    //   return 0;
    // }

    // modify string;
    cleanBuff(inputBuff);
    

    // start spliting program

    int backgroundMode = 0;
    if( inputBuff[strlen(inputBuff) -1]=='&'){
      backgroundMode = 1;
      inputBuff[strlen(inputBuff) -1] = '\0';
    }

    int pid = fork();     
    if(pid >0){
      if(backgroundMode == 0){
        int status, childpid;
        childpid = wait(&status);
        printf("child status: %d\n", status);
      }else{
        printf("Child in background: %i\n",pid);
      }
    }else{
      execlp(inputBuff, inputBuff, 0);
      return 1;
    }

  }
  return 0;
}
