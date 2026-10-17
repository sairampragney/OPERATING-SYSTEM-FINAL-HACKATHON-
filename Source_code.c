#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(void) {
    long size = sysconf(_SC_PAGESIZE);

    int *memory = mmap(NULL, size,
                       PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS,
                       -1, 0);

    if (memory == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    *memory = 100;

    printf("Initial value: %d\n", *memory);
    fflush(stdout);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        munmap(memory, size);
        return 1;
    }

    if (pid == 0) {
        printf("Child before write: %d\n", *memory);
        *memory = 200;
        printf("Child after write: %d\n", *memory);
        munmap(memory, size);
        _exit(0);
    } else {
        waitpid(pid, NULL, 0);
        printf("Parent after child write: %d\n", *memory);
        munmap(memory, size);
    }

    return 0;
}
