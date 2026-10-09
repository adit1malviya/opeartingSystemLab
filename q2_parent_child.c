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

    if (pid == 0)
        printf("This is the child process. PID = %ld\n", (long)getpid());
    else {
        printf("This is the parent process. PID = %ld\n", (long)getpid());
        wait(NULL);
    }
    return 0;
}
