
#include        <stdio.h>
#include        <fcntl.h>
#include        <unistd.h>

main ( )
{
        int fd, k, nb;
        char buf [6];

        k = dup ( 0 );
        fd = open ( "fileB", O_RDWR );
        nb = read ( k, buf, 5 ); // reads "That girl"
              write ( fd, buf, nb ); // writes to file, "That "
              lseek(fd,3, SEEK_CUR);  // seeks 3 on right 
          nb = read ( fd, buf, 7 );  // reads ""
              write ( 1, buf, nb ); // outputs: ""
              nb = read ( 0, buf, 4 ); // reads from input "" --- "girl"
              write ( 1, buf, nb ); // writes to ouput the input -- "girl "
        close ( fd ); close ( k ); // close file and 0
        write( 1,"\n",1 ); // write \n 
        execlp ( "cat", "cat", "fileB",0 ); // prints fileB so  "That "
}

/*output:
"girl"
"That "
*/ 
