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
        for (int i = 1; i <= 19; i += 2)
            printf("Child (odd): %d\n", i);
    } else {
        for (int i = 2; i <= 20; i += 2)
            printf("Parent (even): %d\n", i);
        wait(NULL);
    }
    return 0;
}
