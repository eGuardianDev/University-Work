#include <iostream>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <chrono>
#include <thread>


int main(int argc, char** argv){
  int freq = 2000; // freq in hz
  int len = 1000; // len in ms

  int fd = open("/dev/console", O_WRONLY);
  ioctl(fd, KIOCSOUND, (int)(1193180/freq));
std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
  ioctl(fd, KIOCSOUND, 0);
}