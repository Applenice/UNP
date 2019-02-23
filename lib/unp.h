#ifndef __unp_h
#define __unp_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>    /* basic socket definitions */
#include <sys/time.h>      /* timeval{} for select() */
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>    /* sockaddr_in{} and other Internet defns */
#include <arpa/inet.h>     /* inet(3) functions */
#include <unistd.h>
#include <sys/wait.h>

#define	MAXLINE 4096    /* max text line length */
#define LISTENQ 1024    /* 2nd argument to listen() */
#define	SERV_PORT 9877  /* TCP and UDP */

ssize_t writen(int, const void *, size_t);
void Writen(int, void *, size_t);

int sockfd_to_family(int);
int Sockfd_to_family(int);

const char *Inet_ntop(int, const void *, char *, size_t);
void Inet_pton(int, const char *, void *);

char *sock_ntop(const struct sockaddr *, socklen_t);
char *Sock_ntop(const struct sockaddr *, socklen_t);

ssize_t readn(int, void *, size_t);
ssize_t Readn(int, void *, size_t);

ssize_t readline(int, void *, size_t);
ssize_t Readline(int, void *, size_t);

void str_echo(int);
void str_cli(FILE *, int);

typedef void Sigfunc(int);
Sigfunc *Signal(int, Sigfunc *);

#endif
