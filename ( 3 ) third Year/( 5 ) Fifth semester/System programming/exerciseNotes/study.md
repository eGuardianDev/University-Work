
# 1 file descirptor


kernal controls everything ,it is hidden, we use special commands

file descriptors - used to talk between 2 processes


fd - обмен на данни, например анонимна тръба (a.k.a. queue) 

има подредба на данните, иначе race condition.



# 2 files and permissions
user, group

---rwx---rwx
set_user_ID
set_group_ID

sticky bit - execute by owners name (passwrd root/login root)

атрибутите за писват в постоянната памет

in unix all files have permissions


names are used for processes to find objects


hard links
Inode - tree 
direction to every attribute and data

open - fd


# 3 read,write,close

operation file descriptor:
read, write, close

files are arrays and have other operations:
- change lseek
- change size
- etc.



kernal keeps count of fd and processes uses

Важно: ако fd е към обект в **простанството на имената**, докато има ненулеви процеси, е и *твърда връзка*

един inode, няколко имена

fd се ползва от създателя (процес) и неговите деца


open - file
pipe - наименувана тръба


####  close 
close - прекратява връзката на даден файлов дескриптор

ос-а брои аквини връзки (fd), и твърди връзки
файла изтрива се при 0 - unix standart

Пример: полезно ако трием имената, и добавяме нова версия със същите имена. програмите продължават. докато не приключат старите библиотеки съществуват.


#### read,write
-1 error

0>= read/write bytes


- EINTR - бавно системно извикване, данните не могат да бъдат записани или прочетени, и процеса бива приспан. Понякога се чака данни от I/O устройство или интернет, което може да е цяла вечност

- EAGAIN - вместо да се приспи процеса, просто се извежда грешката. Ползва се при server-и


асинхронна работа - flag O_NONBLOCK




# 4


пространство на имената - файлвое, тръби, периферни устройства. може Read/Write


open, openat, creat

open - идентификация на обект по име, проверки, настройки, комуникационен канал се създава и се връща fd

`<name, inode>`
ако се отвори се губи name

open:
1) проверка за exist
2) read/write rules


#### open
само чрез open може да се създаде нов файл!


- O_RDONLY
- O_WRONLY
- O_RDWR

- O_CREAT
- O_TRUNC
- O_APPEND
- O_EXEC    

- O_NONBLOCK
- O_TMPFILE

```c
creat() // == open(O_CREAT|O_WRONLY|O_TRUNC)
```


ls
```
- масив обектен файл
c char device - поток
b block device - arrays 

p pipe (named)
l symbolic links
s socket - изпозлва други системни извиквания, но пак връща fd
```

pipes и char devices - нямат адресация понеже са FIFO
block devices  -имат адресация понеже са arrays


arrays - може процеса никога да не се приспива
FIFO - може процеса да се приспи, ако искаме повече bytes отколкото има - дълги системни извиквания - могат да са пръсвания от UNIX signal

при масиви truncate, се озоваваме накрая, или да позлваме lseek(), позицията се асоциатира с file descirptor
при array не може да сменяме позицията, защото винаги сме отпред

#### lseek
lseek(fd, +/-offset, whence)
whence:
- seek_set - начало
- seek_end
- seek_cur

отицателна стойност няма на lseek

returns position in bytes from start

може да имаме >seek_end и се запълват с нули празните места


несъщестуващ сектор:
- чете - чете нули
- пише - създава се сектора



# 5
pipe(2), pipe(7), mkfifo(3)

именувана и неименувана нямат разлика в ядрото като имплементация

процес:
1) анонимна тръба
    - pipe(fd[2])
    - използва се само от fork() процеси
2) именувана тръба
    - mkfiifo("./dir/name", mode);
    - намира се в пространството от имена

read/write works normally because "streams"


1) read/write are slow
2) can be used asyncronous with O_NONBLOCK (sleeps can be long)

асинхронна тръба (fcntl)

pipe2()
- O_CLOEXEC, O_DIRECT, O_NONBLOCK




# 6
Stat(2), chmod(2), chown(2), umask(2), utime(2)


1)  stat - всичко надолу ще върне структура подобна на inode (без номера му)
    1) stat("name", statsbuf)
    2) fstat("name", statsbuf)
    3) lstat("name", statsbuf) - символна връзка - soft link *
    4) fstatat(fd, "name", statsbuf,flag) 

* при софт линковете ще се продължи по верига от софт линкове докато не се стигне истински обекти, Например при подаване на soft link на fd

идентифициране:
- по пълно име
- физическо id
    - физическо устройство върху което се намира файла
    - i-node

stat ще върне съхраняващото устройствтото


при добавяне на твърди връзки е като дърво, които сочат към един и същ корен. 

- link() броя се увеличава на твърдите връзки
- unlink() броя намаля



#### дупки
- lseek(), ftruncate()
- само в мета данните, не във VFS
- маркират се че са неотеделени блокове
- read чете винаги нула
- write заделя се място


2) chmod - change mode
    1)  chmod("name", mode)
    2)  fchmod(fd, mode)
    3)  fchmodat(fd,"name", mode,flag)
- mode е цяло число
- собственика има право да сменя правата


3) chown(2) - change owner
    1) chown("name",owner, group)
    2) fchown(fd,owner, group)
    3) lchown("path",owner, group) - soft/csymbol link
    4) fchownat(fd,"path",owner, group,flag)
- собственика отново
- само сменя групата ако е част от новата


4) umask(2)
- извиква - дава я
- аргументира - слага я
    - запомняме старата и може да я въстановим
- umask(mode_t mask)


5) utime, utimes - сменя времето на 
    - utime("name", utimebuf*)
    - utime("name", utimebuf times[2])



# 7 
fcntl(2), dup(2)

1) fcntl
    - fcntl(fd, cmd)
    - lock file
    - unlock file
    - etc.

2) dup
    - dup(oldfd)
    - първото свободно го връща като копие
    - споделят inode, тоест lseek манипулира и двете еднакво


- dup2(old, new)
    - new се затваря и след това дублира на old
        - ако се пресъздаде чрез close and dup, може да има race condition, заради забавяне или interupt
    - ако old е невалиден, нищо не прави над new
    - връща new


error -1
success 0>=



- чрез fcntl може да разбираме настройки на fd и така да избягваме неочаквани странни ефекти. 
Примерно един процес сменя fd да е асинхронен и другите мислят че всичко е наред, накрая всичко се чупи.


F_GETFD вземаме флаговете на специфичен fd
F_GETFD, така променяме фалговете   
- `int flags = fcntl(fd, F_GETFD)` 
- `fcntl(fd, F_GETFD, flags)` 


преди pipe2(pipe[2],flags)
 се ползвало pipe и fcntl



accept(socketfd, addr, addrlen)
- блокираща операция

accept4(socketfd, addr, addrlen, flags)
- асихронен режим

SOCK_NONBLOCK, SOCK_CLOEXEC

# какво е асинхронно
Проблема при операциите за четене и писане, че те могат да блокират процеса. Ако имаме опашка (pipe / char driver) или сокет (socket), тези извиквания чакат докато не получат информация, процеса забива над тях и той блокира докато не дойдат данни.
При асинхрония режим, тези извиквания ще върнат:

- EINTR (Interupted system call)- бавно системно извикване, данните не могат да бъдат записани или прочетени, и процеса бива приспан. Понякога се чака данни от I/O устройство или интернет, което може да е цяла вечност

- EAGAIN (Resource unavailable, try again)- вместо да се приспи процеса, просто се извежда грешката. Ползва се при server-и. Това се наглася чрез `FCNTL`





# 8 
link(2), symlink(7), unlink(2)


- symlink() - soft link

hard link е само за файлове от FS


- софт линк е само един string
- опрерации над софт линк
 - l-..
 - lchown
 - lutime
- ако искаме да направим fd към soft link, а не файла към който сочи, трябва при опрациите да се ползва O_NOFOLLOW



- soft and hard link чупят дървовидната структура на FS (образуват цикли)

при операции, които позволяват symb link има механизъм, константа, която като се достигне се сигнализира ELOOP грешка

- unlink трие soft link-а


symlink("name", "linkName")

unlink("name") - намаля с 1 твърдата връзка или изтрива soft link

link(oldName, newName)
- извлича се `<oldName, Inode>` и се създава `<newName, Inode>`
- трябва да сме в еднаква FS
- не се различават връзките, понеже timestamps и др идват от Inode, а те сочат към едно и също



# 14
signal(7), signal(2), kill(2), pause(2), alarm(2)

асихронни реалцкии (не синхронизирани с файлове, пространство от атрибути и имена, процеси и канали)
- hardware interupt
    - идеята е различни части, системи и периферия да се синхронизират
    - паралелно работещи части да комуникират

Пример: пращане на диска да чете, той го прави бавно, програмата продължава, след това се вика interupt и кода спира да вземи даните отново

- software interupt
    - един обект съобщава надруг обект че нещо има 
        - parent - child
        - etc.


- оригинално са 20 преоцас, в сегашния unix са 30-40
- приличат на h/w interupt
- **exception** е същото като interrupt


Стандартните:
 - Ign (ingore)
 - Term (terminate) - като exit
 - Core (core error) - лошо
 - Stop 
 - Cont (Continue)



- signal()

Нужда от сигнал:
1) реакция при нужда
2) контрол на множество работещи процеси


файлове, пр-во от имена, канали нямат механизъм за контрол над процеси


- kill() изпраща сигнал до
    - един процес
    - група
    - всички
    - АКО ИМА НЯКОЛКО НИШКИ - се праща само до една от тях

- маскиране на сигнали
- временно спиране на реакцията от сигнали


- SIGKILL, SIGSTOP не могат да са хванати, блокирани, игнорирани



- pause(), чака сигнал
- alarm(seconds), планира изпращане на SIGALARM
    - при извикване на alarm, се връща стария брояч, той се анулира и се почва нов



# 15 socket


socket(), bind(), listen(), accept(), connect()

двупосочно, две тръби

? server-а се именува, клиента не

- socket - създва socket

Сървърни:
- bind   - слага го към даден ip:port
- listen - подготвя го да може да слуша за идващи заявки
- accept - приема заявката
    - тука може да се създаде fork, който да обработва заявката

Клиентски:
- connect - праща се заявка за свързване

# 16 shm_overview(7), shm_open(3), ftruncate(2), mmap(2)
Споделена памет

1) споделена памет и семафори
2) съобщения


- shm_open("name", oflag, mode) -> пространто от имена
    - намира се в /dev/shm
        - oflag е като на файлове
        - mode е като правила за достъп
- ftruncate(fd, length) -> оразмеряване на споделена памет
    - работи и за файлове
        - ако е по-малък размер - реже
        - ако е по-голям размер - добавя виртуални нули 
    - модефицира адресната таблица, няма данни там, но осигурява мястото
- mmap(addr, length, prot, flags, fd, offser) -> присъединява споделената памет към адресното пространство на процеса
    - файл - се задава от кой байт на файла и каква дължина
    - споделена памет - offset-а е нула, понеже цялата ще се ползва

    