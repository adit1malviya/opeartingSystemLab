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
    int n;
    printf("Enter a non-negative integer (0 to 20 for factorial): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) return 1;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        if (is_prime(n)) printf("Child: %d is prime.\n", n);
        else printf("Child: %d is not prime.\n", n);
    } else {
        wait(NULL);
        unsigned long long fact = 1;
        for (int i = 2; i <= n; i++) fact *= (unsigned long long)i;
        printf("Parent: %d! = %llu\n", n, fact);
    }
    return 0;
}
