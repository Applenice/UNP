#include "unp.h"
/* cmd: ./daytimetcpcliv6 ::1  */

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in6 servaddr;

    if (argc != 2)
    {   
        printf("argc error\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
    {   
        printf("create sockfd fail\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;
    servaddr.sin6_port = htons(13); /* daytime server */
    if (inet_pton(AF_INET6, argv[1], &servaddr.sin6_addr) <= 0)
    {   
        printf("inet_pton error\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    {   
        printf("connect error\n");
        exit(1);
    }

    while ((n = read(sockfd, recvline, MAXLINE)) > 0)
    {
        recvline[n] = 0; /* null terminate */
        if (fputs(recvline, stdout) == EOF)
        {   
            printf("read error\n");
            exit(1);
        }
    }

    if (n < 0)
    {
        exit(1);
    }

    exit(0);
}
