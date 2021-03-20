#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 100

void error_handling(char *message);

int main(void)
{
    int filedes;
    char buf[BUFSIZE];

    filedes = open("data.txt", O_RDONLY);
    if(filedes == -1)
        error_handling("open() error");
    
    printf("Opened file descriptor is %d.\n", filedes); // Result : 3

    if(read(filedes, buf, sizeof(buf)) == -1)
        error_handling("read() error");
    
    printf("File content : %s", buf);
    
    close(filedes);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}