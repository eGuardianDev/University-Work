#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

int min(int a, int b){
  return (a<b) ? a : b;
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



int cleanBuffEmptyStart(char* input){

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
  for (int first = 0; first<size; ++first){
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

int cleanBuffEmptyEnd(char* input){

  int i;
  int size = strlen(input);
  for(i =size-1;i>=0;--i){
    if(input[i] != ' '){
      if(i +1 != size){
        input[i] = '\0';
      }
      return 0;
    }
  }
  return 1;
}


int checkIfFile(char * input, char divider){

  for(int i = strlen(input)-1; i>=0;--i){
    if(input[i] == divider){
      return i;
    }
  }
  return -1;
}

void printBuff(char *input){
  write(1, "\"", 1);
  write(1, input, strlen(input));
  write(1, "\"\n", 2);

}

int main ()
{

  //display
  char ps1[] = ">";
  
  //data storage
  int const INPUTBUFFERSIZE = 255;
  char inputBuff[INPUTBUFFERSIZE];


  while(1){
    // write to console
    write(1,ps1,strlen(ps1));
    //read form console
    int red = read(0,inputBuff, INPUTBUFFERSIZE);

    // EOF or CTRL + D -> end program   
    if(red ==0){
      write(1,"\n",1);
      return 0;
    }    

    // if EOF is passed as argument
    inputBuff[min(red-1, INPUTBUFFERSIZE-1)] = '\0';

    // valid argumnets
    if(red>0 && red <= INPUTBUFFERSIZE){
      if(inputBuff[red-1] == '\n') inputBuff[red-1] = '\0';
    }

    // exit
    if(compareString(inputBuff, "bye") == 0){
      printf("Bye!\n");
      return 0;
    }

    // fix if empty at beginning
    cleanBuffEmptyStart(inputBuff);
    // fix if empty at end
    cleanBuffEmptyEnd(inputBuff);

    char *argv[64];
    int argc =0;
    char *p = inputBuff;

    int hasFileOut = 0;
    while(*p){
      argv[argc] = p;
      ++argc;
      while(*p && *p != ' ' && *p != '>') ++p; // skip until empty 
      if(*p && *p == ' ') {
        *p = '\0';
        ++p;
      } // if next is empty
      if(*p && *p == '>'){
        *p = '\0';
        ++p;
        hasFileOut = 1;
        break;
      }
      while (*p && *p == ' ') ++p; // skip until fine
    }
    argv[argc] = NULL;


    // get file name
    char *file;
    if(hasFileOut){
      while(*p && *p == ' ') ++p; // skip empty
      file = p;
      while(*p && *p != ' ') ++p;
      if(*p && *p == ' ') *p = '\0';
    }

    if(argc == 0) continue;

    int backgroundMode = 0;
    if(argv[argc-1][0] == '&'){
      argc--;
      argv[argc] = NULL;
      backgroundMode = 1;
    }else if (argv[argc -1][strlen(argv[argc-1])-1] == '&'){
      argv[argc -1][strlen(argv[argc-1])-1] = '\0';
      backgroundMode =1;
    }

    int pid = fork();     
    if(pid == -1){
      write(1, "Error fork",10);
      continue;
    }
    


    if(pid >0){
      if(backgroundMode == 0){
        int status;
        wait(&status);
        printf("child status: %d\n", status);
      }else{
        printf("Child in background: %d\n",pid);
      }
    }else{  
      if(hasFileOut){
        close(1);
        open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);
      }
      if(backgroundMode){
        close(0);
      }
    // for(int i=0;i<argc;++i){
    //   printBuff(argv[i]);
    // }
    // if(hasFileOut){
    //   write(1, "in file: ",9);
    //   printBuff(file);
    // }
      execvp(argv[0], argv);
      write(1, "Command not found.\n", 19);
      exit(2);
    }

  }
  return 0;
}
