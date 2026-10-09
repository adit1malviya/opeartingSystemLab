/* Assignment title: permutation_child.c
   The provided task description asks the child to sum an array and test primality. */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_prime(long long n) {
    if (n < 2) return 0;
    for (long long i = 2; i <= n / i; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    int n, a[100];
    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%d", &a[i]) != 1) return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        long long sum = 0;
        for (int i = 0; i < n; i++) sum += a[i];
        printf("Child: sum = %lld\n", sum);
        printf("Child: sum is %sprime.\n", is_prime(sum) ? "" : "not ");
    } else {
        wait(NULL);
        printf("Parent: child completed.\n");
    }
    return 0;
}
