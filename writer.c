#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int fd;
    char message[100];
    mkfifo("myfifo",0666);
    fd=open("myfifo",O_WRONLY);
    if(fd==-1)
    {
        perror("open");
        return EXIT_FAILURE;
    }
    printf("Enter message");
    fgets(message,sizeof(message),stdin);
    write(fd,message,strlen(message)+1);
    return EXIT_SUCCESS;
}