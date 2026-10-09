#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Please enter n from 0 to 20.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        unsigned long long a = 0, b = 1, fact = 1;
        printf("Child: First %d Fibonacci terms: ", n);
        for (int i = 0; i < n; i++) {
            printf("%llu ", a);
            unsigned long long next = a + b;
            a = b;
            b = next;
        }
        for (int i = 2; i <= n; i++) fact *= (unsigned long long)i;
        printf("\nChild: %d! = %llu\n", n, fact);
    } else {
        long long sum = (long long)n * (n + 1) / 2;
        wait(NULL);
        printf("Parent: Sum of first %d natural numbers = %lld\n", n, sum);
    }
    return 0;
}
