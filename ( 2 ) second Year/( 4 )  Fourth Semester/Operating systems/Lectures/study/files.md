# Files in linux

## Permissions and file types

|symbol| number| permission|
| ---|---| --- |
|r | 4 | Read |
|w | 2 | Write |
|x | 1 | eXecute |


```bash
> ls -al myFile

"permissions hard-links  user  group  size  date    time   name"
 -rwxrwxrw-    1          doge  dogs   69    APR 25  12:41  myFile
```

## file type: ( 7 types )
```bash
 -rwxrwxrw-
"^--- this symbol here is the file type"
```
|symbol| definition|
|---|---|
| - | file|
| d | directory|
| l | (hard and soft/symbolic) link|
| b | block device files ( anything that stores data like hdd, sdd, flash drives, etc. )|
| c | character device files ( mouse, keyboard, monitor, printer )|
| s | local sockets  - IP and unique port - 'sendmsg() and recvmsg() for inter-process communication between local applications' |
|p | named ( and standart ) pipes  |

#### pipe types (uses FIFO mechanism):
       standart - connect processes under same      user account  ( or Parent processes)
       named    - connect processes under different user accounts ( or Parent processes)

### identify file type:
```bash
file <file>
```

### tutorials:
- [video - opening files in c](https://www.youtube.com/watch?v=saMebwRO-Q8)

### references :
- [video - Types](https://www.youtube.com/watch?v=EDgkcvOoY8A)
- [video - File tpyes explained](https://www.youtube.com/watch?v=42iQKuQodW4&pp=ygUQbGludXggZmlsZSB0eXBlcw%3D%3D)
- [docs - File types explained ](https://www.computernetworkingnotes.com/linux-tutorials/different-types-of-files-in-linux.html)
- [video - permissions](https://www.youtube.com/watch?v=42iQKuQodW4&pp=ygUQbGludXggZmlsZSB0eXBlcw%3D%3D)
