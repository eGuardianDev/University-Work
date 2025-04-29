# Booting and processes

process is program in execution
when is not executed it is called program

Thread is a unit of execution in process
One process can have many threads


### processes types
Need to be executred in real time and not delayed
#### Real-time processes
Two real-time processes:
 - SCHED_FIFO - First in first out.
 - SCHED_RR - Round Robin, gives specific fixed amount of time for execution.

priority 1 to 99. This processes are dealts with more than 0 priority.

#### Normal processes
can suffere from delay, because of less priority.
 - Normal (SCHED_NORMAL, SCHED_OTHER) standart policy. Normal policy deal with not real-time processes. 
 Gives specific amount of time for processes execution.
 - Batch (SCHED_BATCH) - deals with non-interactive processes that are usefull for CPU optimization.
 - Idle (SCHED_IDLE) - deals with extremely low priority processes. 

 normal and batch deal with priority 0

O(n) and O(1) schedulers
- n is the number of processes, processor time is divided in units called epochs
- O(1) uses 2 queues, run queue and expired queue

Completely Fair Scheduler (CFS). aims for cpu optimizations and performance. uses red-black trees insted of queue

Dynamics priority. priority is calculated at time of execution

Virtual runtime. the time spend in execution, may not include response and wait time.

Most important task of multiprogramming is using the cpu 100%. Time sharing is so that every processes seems working at the same time.

#### Queues:
 - Job queue - when process enters the system it is put into job queue. All available processes.
 - Ready queue - processes in main memory, ready for execution (managed by CPU Scheduler, FIFO)
 - Waiting queue - processes waiting for something, like I/O evenet

other ( not sure if used or standart ):
 - partially executed, swapped-out processes - when processes with higher priority is queue, current process is temporary removed from execution. after this goes to ready queue.
 - device queue - processes waiting for I/O device to become available
if processes with higher  

### Context switching
interupts that cause the system to be changing processes, saving the state of processes so it can continue after that.
Context switching is wasted time, because the system doesn't do anything usefull during this period. Typically a few milli seconds.


### first process
when the system first boot init process is created and new processes come from it. normally with pid 1. (sometimes different for virtualization)
In modern linux kernal it is called Systemd 


|Process data|Purpose|
|---|---|
| Process ID (PID) |gives id to process |
| Parent PID | pid of parent of process (the process that spawned/init it) |
| effective User id | owner of process |
| group id (gid) | file creation ( not used often? )|
| egid | used when file creating is used|
| niceness (NI) | how much resources halts |
| Priority | need for execution (scheduler uses this) |

All processes (except init) are created by parent processes.
Every processes forks (clones) itself and the clone starts another program.

Init is started by the Kernal with PID of 1. Then Init starts other init scripts (depends on distro).

### some commands
exec - current bash is not this program

sleep 100   - run sleep for 100 seconds
sleep 100 & - run sleep for 100 seconds in background

fg - foreground - change process to foreground
bg - background - change process to background

jobs - get current background jobs
"+" last called job
"-" second last called job


### Processes states



#### Overall states
**New** - processes is being initiated
**Ready** - ready for execution, but not executed (waits for scheduler)
**Running** - 
 - Interupted  -> **Ready** ( context switching )
 - waiting I/O, waiting, etc. -> **Waiting** 
 - error, finishes work -> **Terminated**
**Waiting**
 - waited operation completes -> **Ready** ( waits to be scheduled to continue, most often for thread/core to be free for work)
**Terminated** - process ends, returns exit code



#### All states

|Symbol|Name|Definition|
|---|---|---|
|R|Running|running or in running queue|
|S|Sleeping|Waiting to event (can be interupted)|
|D|(deep?) Uninterruptable Sleep|Waiting for I/O. cannot be interrupted|
|Z|Zombie|Waiting parent to collect exit code (finished, but still in process table)|
|T|Stopped|Stopped by a signal, (for example kill command -> SIGSTOP, SIGSTP)|
| |Rare once | |
|t|tracking stopped|Stopped, but with trace (strace)|
|X|Dead (rare)| Mark for removal (not usually seen)|
|I|Idle| For kernal threads (shown on newer kernals)|


table.

Terminated - stopped or being stopped

Suspended - similar to stopped (T), can be continued with kill -CONT

Running

Ready

### Possible problems
- io bound - process is slowed from i/o operations and not from cpu
- cpu bound - process is slowed by cpu 

- real-time
 - Hard real-time. Used in system for medical, military, space or other time sensitive operations
 - soft real-time. video streaming, audio streaming, gaming


### supervisor 
when program is making a system call it transitions from user mode to supervisor mode.
This program controls jobs, manages memory, handles I/O


### Killing processes

kill (-15)
kill -2
kill -1 
kill -9 - this doesn't give option for the program to clean up

crtl + z == kill -19



### finding processes

pgrep <process> - gives process id

htop - better top




### find file

find 
-type d directory
-type f file

-name "name"
-name "*.txt"

-exec echo "this is the file -> " {} \; (or + insted of \; for running in concat mode)

-user "owner"
-group
-perm 744 (permissions)
-size +1G (More than 1 gigabyte)


## Resources:
- [video booting](https://www.youtube.com/watch?v=XpFsMB6FoOs)
- [video processes](https://www.youtube.com/watch?v=TJzltwv7jJs)
- [video managing](https://www.youtube.com/watch?v=LfC6pv8VISk)
- [video processes states](https://www.youtube.com/watch?v=DacMRZRc4Bo)
- [video process management](https://www.youtube.com/watch?v=OrM7nZcxXZU)

- [video program scheduled](https://www.youtube.com/watch?v=OrM7nZcxXZU)
- [video process scheduled 2](https://www.youtube.com/watch?v=2h3eWaPx8SA)
- [docs schedules](https://www.scaler.com/topics/operating-system/process-scheduling/)

- [video find commands](https://www.youtube.com/watch?v=FvEoGHFKsKA)

- [Playlist processes](https://www.youtube.com/playlist?list=PLtK75qxsQaMKLUENMaPlD_O2qS8ZBGjuy)
