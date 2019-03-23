#include "unp.h"
#include <time.h>

int main(int argc, char **argv)
{
    int listenfd, connfd;
	socklen_t len;
    struct sockaddr_in6 servaddr, cliaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET6, SOCK_STREAM, 0)；

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;
    servaddr.sin6_addr = in6addr_any;
    servaddr.sin6_port = htons(13);    /* daytime server */

    Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    Listen(listenfd, 1024);

    for ( ; ; )
    {	
		len = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *) &cliaddr, &len);
        printf("connection from %s\n", Sock_ntop((struct sockaddr *) &cliaddr, len));
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        Close(connfd);
    }
}
