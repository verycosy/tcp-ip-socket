#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void error_handling(char *message);

int main(void)
{
    int filedes;
    char buf[] = "Lets's go!\n";

    filedes = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    if(filedes == -1)
        error_handling("open() error");

    printf("Created file descriptor is %d\n", filedes); // Result : 3

    if(write(filedes, buf, sizeof(buf)) == -1)
        error_handling("write() error");
    
    close(filedes);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}