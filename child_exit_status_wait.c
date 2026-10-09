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
        printf("Child: exiting with status 10.\n");
        exit(10);
    }

    int status;
    if (wait(&status) == -1) {
        perror("wait");
        return 1;
    }
    if (WIFEXITED(status))
        printf("Parent: child exit status = %d\n", WEXITSTATUS(status));
    else
        printf("Parent: child did not exit normally.\n");
    return 0;
}
