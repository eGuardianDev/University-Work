#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()

void main(){

int pid, var = 1, status;
if (( pid = fork()) == 0 ) {var+=2;
printf ("\n Var = %d ", var);}
else { wait(&status); var++ ;
printf ("\n Var = %d ", var);
exit(0);}
--var;
printf ("\n Var = %d ", var);

}
