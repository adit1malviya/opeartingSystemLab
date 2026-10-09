#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int terms, number;
    printf("Enter number of Fibonacci terms: ");
    if (scanf("%d", &terms) != 1 || terms < 0) return 1;
    printf("Enter number for factorial: ");
    if (scanf("%d", &number) != 1 || number < 0 || number > 20) {
        printf("Use a factorial number from 0 to 20.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        unsigned long long a = 0, b = 1;
        printf("Child: Fibonacci series: ");
        for (int i = 0; i < terms; i++) {
            printf("%llu ", a);
            unsigned long long next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    } else {
        unsigned long long fact = 1;
        for (int i = 2; i <= number; i++) fact *= (unsigned long long)i;
        printf("Parent: %d! = %llu\n", number, fact);
        wait(NULL);
    }
    return 0;
}
