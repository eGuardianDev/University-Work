#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (int argc, char *argv[] )
{
  if(argc != 4){
    printf("Not enought arguments. Usage: %s {cmd1} {cmd2} {cmd3}\n", argv[0]);
    return 1;
  }
  

  int status;

    // Run first command
    int pid = fork();
    if (pid == 0) {
        printf("Running %s\n", argv[1]);
        execlp(argv[1], argv[1], NULL);
        return 1; // return non-zero if failed
    } else {
        wait(&status);
        if (status == 0)
            printf("%s finished successfully\n", argv[1]);
        else
            printf("%s failed\n", argv[1]); 
    printf("status %i\n", status);
  }


    // Run first command
    pid = fork();
    if (pid == 0) {
        printf("Running %s\n", argv[2]);
        execlp(argv[2], argv[2], NULL);
        return 1; // return non-zero if failed
    } else {
        wait(&status);
        if (status == 0)
            printf("%s finished successfully\n", argv[2]);
        else
            printf("%s failed\n", argv[2]);
      printf("status %i\n", status);
    }

    // Run first command
    pid = fork();
    if (pid == 0) {
        printf("Running %s\n", argv[3]);
        execlp(argv[3], argv[3], NULL);
        return 1; // return non-zero if failed
    } else {
        wait(&status);
        if (status == 0)
            printf("%s finished successfully\n", argv[3]);
        else
            printf("%s failed\n", argv[3]);
      printf("status %i\n", status);
    }
  return 0;
}
