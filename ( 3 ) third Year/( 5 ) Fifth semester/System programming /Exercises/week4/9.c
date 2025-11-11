#include        <stdio.h>
#include        <fcntl.h>
#include        <unistd.h>

int main ( )
{
  int fd, j, nb1;
  char buf [5];
  j = dup ( 1 );
  fd = open ( "fileA", O_RDWR );
  nb1 = read ( 0, buf, 4 ); 
  write ( j, buf, nb1 ); // print 4 from 0 to 1 
  nb1 = read ( fd, buf, 5 );  
  write ( 1, buf, nb1 );  // prints to 1 from file 5<= bytes 
  write ( fd, buf, nb1 ); // prints to file the 5<= bytes 
  write ( j, buf, 3 );    // prints to j(1) 3 bytes from buf 
  close ( fd ); close ( j );
  write( 1,"\n",1 );     // new line to 0
  execlp ( "cat", "cat", "fileA",0 ); // reads file
}

// >> Fish 
// Fish|cat m|
// file is "cat meow woof|cat m" !!! no, actually: file from "cat meow woof" => "cat mcat moof"
// // cat|cat
//
// cat meow woofcat m -> cat mcat moof
