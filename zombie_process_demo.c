#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child: exiting now. PID = %ld\n", (long)getpid());
        fflush(stdout);
        _exit(0);
    } else {
        printf("Parent: child PID = %ld. Not calling wait immediately.\n",
               (long)pid);
        fflush(stdout);
        sleep(10); /* During this time, inspect with: ps -el | grep Z */
        printf("Parent: now collecting child status with wait().\n");
        wait(NULL);
    }
    return 0;
}
