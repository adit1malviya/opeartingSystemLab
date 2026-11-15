#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    read(fd, buffer, sizeof(buffer));

    printf("Received: %s", buffer);

    close(fd);

    unlink("myfifo");

    return EXIT_SUCCESS;
}