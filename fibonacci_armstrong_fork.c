#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int is_armstrong(int n) {
    if (n < 0) return 0;
    int temp = n, digits = 0;
    do { digits++; temp /= 10; } while (temp != 0);

    temp = n;
    long long sum = 0;
    do {
        int digit = temp % 10;
        long long power = 1;
        for (int i = 0; i < digits; i++) power *= digit;
        sum += power;
        temp /= 10;
    } while (temp != 0);
    return sum == n;
}

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        int a = 0, b = 1;
        printf("Child: Fibonacci numbers up to %d: ", n);
        while (a <= n) {
            printf("%d ", a);
            int next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    } else {
        printf("Parent: Armstrong numbers from 1 to %d: ", n);
        for (int i = 1; i <= n; i++)
            if (is_armstrong(i)) printf("%d ", i);
        printf("\n");
        wait(NULL);
    }
    return 0;
}
