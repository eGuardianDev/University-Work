# Virtual file system

### Some information 
- POSIX is a standard that helps different operating systems agree on how programs should interact with the system

- VFS - page 296 - [Andrew Tanenbaum OS book](https://csc-knu.github.io/sys-prog/books/Andrew%20S.%20Tanenbaum%20-%20Modern%20Operating%20Systems.pdf)

original purpose - to support NFS (network file system) protocol

Standart POSIX calls for VFS - open, read, write, lseek, etc.

Two interfaces - to the user and to the file system


### Specifics
- Super block - describes the file system, metadata, type, size, number of inodes/blocks, pointer to file system function table
- v-node (virtual inode) - describes a file, file metadata ( permissions, size, timestamps ), pointer to file's inode, **function pointers for file operations, Created when file is accessed by VFS**
- directory - describes a file system directory
- inode (index node) -  stores metadata of files ( without name and content ) : type, permissions, ownership, size, timestamps, link count, pointer to data block

#### v-node vs inode:
- inode - stores data of files, tracks hard links
- v-node - stores functions for files, makes abstraction layer for kernal and different fs, part of VFS layer


### Links:
- soft link 
    - acts as a referenece or pointer to specific file/directory
    - can be broken
    - can link between file systems
```ln -s <file> <link>```
- hard link
    - connected to the same data as original file
    - **cannot** be broken (when deleted the data still exists, until all hard links are deleted)
    - **cannot** link between file systems
```ln <file> <link>```


### mount table
- Keeps track of mounted file systems and where is located.
- Keeps references to superblocks
### How does it work
1. Opens a file. This talks to the VFS 
```c 
open("/usr/include/unistd.h", O_RDONLY);
```
2. VFS checks mount table the file system type (ext3, NFS ...)
3. VFS finds superblock and navigates to the file
4. creates v-node in represents the file (metadata, pointer to fs' function table - read, write, etc)
5. v-node is linked to file descriptor and returns it to the programs

- when read or other operation is called
    - the file descriptor finds the v-node
    - v-node finds the fs read function
    - the data is fetched from fs (remote, usb or local disk)
