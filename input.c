#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    const char *filename = "input.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen for writing");
        return 1;
    }

    char name[100], roll[50], class_name[50];
    printf("Enter name: ");
    if (scanf(" %99[^\n]", name) != 1) { fclose(fp); return 1; }
    printf("Enter university roll number: ");
    if (scanf(" %49s", roll) != 1) { fclose(fp); return 1; }
    printf("Enter class: ");
    if (scanf(" %49[^\n]", class_name) != 1) { fclose(fp); return 1; }

    fprintf(fp, "Name: %s\nUniversity Roll Number: %s\nClass: %s\n",
            name, roll, class_name);
    fclose(fp);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        fp = fopen(filename, "r");
        if (fp == NULL) {
            perror("fopen for reading");
            return 1;
        }
        char line[256];
        printf("\nChild: contents of %s\n", filename);
        while (fgets(line, sizeof(line), fp) != NULL)
            printf("%s", line);
        fclose(fp);
    } else {
        wait(NULL);
        printf("Parent: file created and child finished reading it.\n");
    }
    return 0;
}
