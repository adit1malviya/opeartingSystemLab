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
        printf("Child: PID = %ld, initial PPID = %ld\n",
               (long)getpid(), (long)getppid());
        fflush(stdout);
        sleep(3); /* Give the parent time to exit. */
        printf("Child: after parent exits, PPID = %ld\n", (long)getppid());
    } else {
        printf("Parent: PID = %ld; exiting now.\n", (long)getpid());
        fflush(stdout);
        _exit(0);
    }
    return 0;
}
