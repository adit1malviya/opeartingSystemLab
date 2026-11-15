#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main(void)
{
    key_t key;
    int msgid;
    struct message msg;

    key = ftok(".", 'A');

    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1)
    {
        perror("msgget");
        return EXIT_FAILURE;
    }

    msgrcv(msgid,
           &msg,
           sizeof(msg.text),
           1,
           0);

    printf("Received: %s", msg.text);

    msgctl(msgid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}
