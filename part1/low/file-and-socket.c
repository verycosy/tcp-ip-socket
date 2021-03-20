#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>

int main(void)
{
    int fdes1, fdes2, fdes3;

    fdes1 = socket(PF_INET, SOCK_STREAM, 0); // Result : 3
    fdes2 = open("test.dat", O_CREAT); // Result : 4 or -1
    fdes3 = socket(PF_INET, SOCK_DGRAM, 0); // // Result : 5 or 4

    printf("First FD : %d\n", fdes1);
    printf("Second FD : %d\n", fdes2);
    printf("Third FD : %d\n", fdes3);

    return 0;
}