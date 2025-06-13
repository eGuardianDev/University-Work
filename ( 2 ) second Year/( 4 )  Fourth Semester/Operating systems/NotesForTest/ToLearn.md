
## Block() wakeup(pid)


## links symbolic, hard, ln


## socket
duplex
ls -l --> s

## inode 
data struct to hold the attributes and disk block locations
infomration like owners, permissions, file tpye,


13 secots

first are for meta data
others for link to tables of tables to data of the file/folder

## journal file system
Keeps tract of changed that not yet saved
less change of corruption
journal can be in files on the disk or in other disk/дял

## elevator algorithm
Minimize travel speed of hdd for faster writing/reading.
Different implementations can be used for this, but now

we begin from one part of the disk start the oprations
like a evelator while the disk is going one directions, 
the data for the other is stored in buffer or queue for
later use when the disk is going in the reverse.


## pipe (with or without buffer)
sempahore for buffer
mutex 
редуване

binar mutex / semaphore or just bits/flags

## paging



## bash
test, if

## 13 MMU, TLB
Memory Management Unit
Optimization for MMU is Translation Lookaside Buffer

MMU 
Hardware where all the references for addresses go through
Virtual to physical address transformation
(using tables with pages and tables with segments)
2^n size

TLB 
cache used by MMU for better speed
holds recently calculated addresses
fixed size

using table with pages for changing virtual addresses to physical
using table with segments for changing virtual adresses to segment adresses


## sync, async communication
## socket(), bind(), connect(), listen(), accept()

## „пространство на имената“. Как изглежда това пространство в ОС Linux
Изолация на процесите (като например в bash session). Така те виждат специфични ресурси, процеси, файлови системи, мрежове интерфейси. Всички обекти имат уникални имена и така лесно могат да се различават.

## readers-writers code

## requirements for modern file system

error correciton ,security, scalibility, speed, efficiency, space, space control - defragmentation, 
alogrithms for efficiency ( elevator algorthim for hdd)
sectors
512, 1024 byte size blocks division
fragmentation


