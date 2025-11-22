#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    // Create shared memory for one integer
    int *shared = mmap(NULL, sizeof(int),
                       PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS,
                       -1, 0);

    if (shared == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    *shared = 0;  // initialize

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Child: waiting for parent...\n");

        sleep(1); // give parent time to write

        printf("Child: shared memory value = %d\n", *shared);

        *shared = 200; // modify shared memory

        printf("Child: updated value to %d\n", *shared);
        return 0;
    }

    // Parent process
    printf("Parent: writing to shared memory...\n");

    *shared = 123;

    printf("Parent: wrote %d\n", *shared);

    wait(NULL); // wait for child to finish

    printf("Parent: child updated value to %d\n", *shared);

    return 0;
}

