#include <stdio.h>
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
        printf("Child process: PID = %ld, PPID = %ld\n",
               (long)getpid(), (long)getppid());
    } else {
        printf("Parent process: PID = %ld, PPID = %ld\n",
               (long)getpid(), (long)getppid());
        wait(NULL);
    }
    return 0;
}
