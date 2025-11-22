  
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

  if(argc !=3){
    printf("Not enought args. Usage %s {file_in} {file_out}", argv[0]);
    return 1;
  
  }

  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

  if(fd1 == -1 || fd2 == -1){
    printf("Couldn't open file.");
    return 2;
  }



  char buff[255];
  char buffsend[60];
  int red=0;
  while( (red = read(fd1,buff,255)) !=0){
    int j =0;
    int count= 0;
    for(j = 0;j<red;++j){
      if(buff[j]=='\n' && buff[j-1] == '$'){
        lseek(fd1, -count,SEEK_CUR);
        read(fd1, buffsend, count);
        write(1, buffsend, count);
        lseek(fd1, count,SEEK_CUR);
      }
      else{
      int i;
      int newLine = 0;
      for(i =0 ;i<red; ++i){
        if(buff[i] >= '0' && buff[i]<='9'){
           write(fd2, &buff[i],1);
          newLine = 1;
        }
        else
        {
          if(newLine == 1 ){
            write(fd2, "\n",1);
          }
          newLine = 0;
          }
        }
      }
    }
  }
  close(fd1);
  close(fd2);
}
  


