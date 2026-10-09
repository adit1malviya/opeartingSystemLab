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
        for (int i = 1; i <= 5; i++)
            printf("Child: %d\n", i);
    } else {
        wait(NULL);
        printf("Parent: Child has finished.\n");
    }
    return 0;
}
