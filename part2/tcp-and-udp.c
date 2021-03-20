#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char **argv)
{
    int tcp_socket;
    int udp_socket;

    tcp_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(tcp_socket == -1)
        error_handling("socket() error");

    udp_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(udp_socket == -1)
        error_handling("socket() error");
    
    printf("Created tcp socket's file descriptor : %d\n", tcp_socket);
    printf("Created udp socket's file descriptor : %d\n", udp_socket);

    close(tcp_socket);
    close(udp_socket);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}