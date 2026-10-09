#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    int a[] = {2, 3, 4, 5, 6};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        close(fd[0]);
        int sum = 0;
        for (int i = 0; i < n; i++) sum += a[i];
        printf("Parent: sum = %d\n", sum);
        if (write(fd[1], &sum, sizeof(sum)) != sizeof(sum))
            perror("write");
        close(fd[1]);
        wait(NULL);
    } else {
        close(fd[1]);
        int sum;
        ssize_t bytes = read(fd[0], &sum, sizeof(sum));
        close(fd[0]);
        if (bytes != sizeof(sum)) {
            fprintf(stderr, "Child: failed to read sum from pipe.\n");
            return 1;
        }
        printf("Child: received sum = %d\n", sum);
        printf("Child: received sum is %sprime.\n",
               is_prime(sum) ? "" : "not ");
    }
    return 0;
}
