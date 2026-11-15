#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key;
    int shmid;
    char *shared;

    key = ftok(".", 'S');

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        perror("shmget");
        return EXIT_FAILURE;
    }

    shared = (char *)shmat(shmid, NULL, 0);

    if (shared == (char *)-1)
    {
        perror("shmat");
        return EXIT_FAILURE;
    }

    printf("Enter data: ");
    fgets(shared, 1024, stdin);

    printf("Data written to shared memory.\n");

    shmdt(shared);

    return EXIT_SUCCESS;
}
