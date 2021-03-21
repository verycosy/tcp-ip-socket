#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_handling(char *message);

int main(int argc, char **argv)
{
    char *addr1 = "1.2.3.4";
    char *addr2 = "1.2.3.256";

    unsigned long conv_addr;
    struct sockaddr_in addr_inet;
    
    struct sockaddr_in inet1, inet2;
    char *str;

    conv_addr = inet_addr(addr1);
    if(conv_addr == INADDR_NONE)
        printf("Error Occur : %d\n", conv_addr);
    else
        printf("Unsigned long addr(network ordered) : %x\n", conv_addr); // 4030201

    conv_addr = inet_addr(addr2);
    if(conv_addr == INADDR_NONE)
        printf("Error Occur : %d\n", conv_addr); // -1
    else
        printf("Unsigned long addr(network ordered) : %x\n", conv_addr);

    if(!inet_aton(addr1, &addr_inet.sin_addr))
        error_handling("Conversion Error");

    printf("Unsigned long addr(network ordered) : %x\n\n", addr_inet.sin_addr.s_addr);

    inet1.sin_addr.s_addr = htonl(0x1020304);
    inet2.sin_addr.s_addr = htonl(0x1010101);

    str = inet_ntoa(inet1.sin_addr);
    printf("Dotted-Decimal notation : %s\n", str); // 1.2.3.4

    // 반환하는 문자열 포인터는 함수 내부에 선언되어 있는 static buffer.
    // 따라서 다시 한번 다른 주소 정보를 가지고 호출시 버퍼는 다른 데이터로 채워진다.
    inet_ntoa(inet2.sin_addr);
    printf("Dotted-Decimal notation : %s\n", str); // 1.1.1.1

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}