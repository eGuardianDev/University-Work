# Memory



### Virtual Memory

#### segmentation
there are different types of segmentation. The program is divided in segments - [code](https://en.wikipedia.org/wiki/Code_segment), data (constants), stack, heap, etc. (can vary). Memory is divided in segmentations for programs to use. 

Every program thinks it runs on the whole memory.

In segmentation:
- program is divided into segments
- they vary in size
- they can be stored in swap. 
- os knows every size and where is it in memory
- large segments are not allowed in memory often
- There is the problem that when program or parts of it is not currently executed/used, it is put in swap to free space for another program. If this continues, then **fragmentation** accrues.
- segments can be pushed together to save on fragmentation.


#### paging
OS stores page table and can fragment memory to fit more spaces

in paging:
- one segment is around 4 kb ( every segment equally sized)
- single application may be in multiple pages
- os hold infromation for framents and where they are stored
- pages are paged when needed again
- physical memory is used as secondary storage, called virtual memory ( swap )
- when memory is low, exessive swapping can cause the computer to slow down. 

 - [segmentation fault](https://www.scaler.com/topics/segmentation-fault-in-linux/) - trying to access out of scope memory for specific program. Often found with pointers (null pointers or dangling pointers), buffer overflow (invalid input data size), stack overflow (infinite recursion), freeing memory (if freed pointer is used by another proccess). The os/kernal sends **signal** (this is important - check communication with signals in linux) to the process, that there is segmentation error. The default signal handler terminates the process (crash) 



### modes
- protected modes
- real mode
[info](https://wiki.osdev.org/Segmentation)


lazy operations
fork()
exec()

Intel 386 - first processor with virtual memory?

caches and dram

tlb
table of processes


### Virtual memory (Swap)
Swap is using hdd or ssd as extension of RAM for data that is not often used.
swap space - part of the hdd used to store this data. it is particion (faster) or file (easily expandable) Multiple swap spaces can be made.

- swapping - writting the whole process to the swap space
- paging - writting fixed size parts (few kilobytes) at a time. (more efficient)
^ This is different from physical to ram memory paging for segmentation in [memory](https://tldp.org/LDP/sag/html/vm-intro.html). Also [Forums](https://www.reddit.com/r/linuxquestions/comments/u8vif2/what_paging_technique_does_linux_use/) 

- [virtual memory](https://tldp.org/LDP/sag/html/vm-intro.html)
- [segmentation fault](https://en.wikipedia.org/wiki/Segmentation_fault)

- [memory segmentation](https://en.wikipedia.org/wiki/Memory_segmentation) <- todo: check out this
- [video segments vs pages memory](https://www.youtube.com/watch?v=p9yZNLeOj4s)



Other stuff... (not checked or used yet)
- [x86 mem seg](https://en.wikipedia.org/wiki/X86_memory_segmentation)
- [Memory management](https://wiki.osdev.org/Memory_management)
- [Linux mem managemnet](https://stackoverflow.com/questions/56213569/linux-memory-segmentation)