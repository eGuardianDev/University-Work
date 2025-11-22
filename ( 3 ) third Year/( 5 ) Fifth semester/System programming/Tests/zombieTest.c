#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process: exit immediately
        printf("Child: exiting now...\n");
        exit(0);
    }

    // Parent process: do NOT call wait()
    printf("Parent: child created with PID %d\n", pid);
    printf("Parent: sleeping for 30 seconds... Check 'top' or 'ps' for zombie.\n", pid);

    sleep(30);  // child becomes zombie during this time

    printf("Parent: exiting, zombie will be reaped by init.\n");
    return 0;
}

