#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <sys/wait.h>  // for wait()

#define COM "ps"
void main()
{
int i=2, status;
if ( fork() ) {wait(&status); --i;
printf( " Stoinostta na i = %d;\n", i);}
else { i++;
if ( execlp ( COM, COM, 0) == -1) { i=i+2;
printf( " Stoinostta na i = %d;\n", i);}
}
printf( " Stoinostta na i = %d;\n", --i);
}
