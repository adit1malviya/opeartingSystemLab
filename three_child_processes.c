#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            printf("Child %d: PID = %ld, PPID = %ld\n",
                   i, (long)getpid(), (long)getppid());
            return 0; /* Prevent this child from creating more children. */
        }
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);
    printf("Parent: all three children have terminated.\n");
    return 0;
}
