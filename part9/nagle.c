#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv)
{
    int sock;
    int state, opt_val, opt_len;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    state = getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, &opt_len);

    if(state) {
        puts("getsockopt() error");
        exit(1);
    }

    printf("Default Nagle : %s\n", opt_val ? "OFF" : "ON");

    opt_val = TRUE;
    state = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, sizeof(opt_val));

    if(state) {
        puts("setsockopt() error");
        exit(1);
    }

    getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &opt_val, &opt_len);
    printf("Change Nagle : %s\n", opt_val ? "OFF" : "ON");
    close(sock);
    return 0;
}