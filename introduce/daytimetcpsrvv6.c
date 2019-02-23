#include "../lib/unp.h"

int main(int argc, char **argv)
{
    int listenfd, connfd;
	socklen_t len;
    struct sockaddr_in6 servaddr, cliaddr;
    char buff[MAXLINE];
    time_t ticks;

    if ((listenfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
    {   
        printf("create listenfd fail\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin6_family = AF_INET6;
    servaddr.sin6_addr = in6addr_any;
    servaddr.sin6_port = htons(13);    /* daytime server */

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listenfd, 1024);

    for ( ; ; )
    {	
		len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len);
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));

        close(connfd);
    }
}
