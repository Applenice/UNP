#ifndef __unp_h
#define __unp_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>    /* basic socket definitions */
#include <sys/time.h>      /* timeval{} for select() */
#include <time.h>

#include <netinet/in.h>    /* sockaddr_in{} and other Internet defns */
#include <arpa/inet.h>     /* inet(3) functions */
#include <unistd.h>

#define	MAXLINE 4096    /* max text line length */
#define LISTENQ 1024    /* 2nd argument to listen() */
#define	SERV_PORT 9877  /* TCP and UDP */

void str_echo(int);
#endif
