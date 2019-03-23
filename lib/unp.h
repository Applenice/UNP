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

#include <sys/select.h>

#define MAXLINE 4096    /* max text line length */
#define LISTENQ 1024    /* 2nd argument to listen() */
#define SERV_PORT 9877  /* TCP and UDP */

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

void Fclose(FILE *);
FILE *Fdopen(int, const char *);
char *Fgets(char *, int, FILE *);
FILE *Fopen(const char *, const char *);
void Fputs(const char *, FILE *);

int Accept(int, SA *, socklen_t *);
void Bind(int, const SA *, socklen_t);
void Connect(int, const SA *, socklen_t);
void Getpeername(int, SA *, socklen_t *);
void Getsockname(int, SA *, socklen_t *);
void Getsockopt(int, int, int, void *, socklen_t *);

#ifdef HAVE_INET6_RTH_INIT
int Inet6_rth_space(int, int);
void *Inet6_rth_init(void *, socklen_t, int, int);
void Inet6_rth_add(void *, const struct in6_addr *);
void Inet6_rth_reverse(const void *, void *);
int Inet6_rth_segments(const void *);
struct in6_addr *Inet6_rth_getaddr(const void *, int);
#endif

#ifdef HAVE_KQUEUE
int Kqueue(void);
int Kevent(int, const struct kevent *, int, struct kevent *, int, const struct timespec *);
#endif

void Listen(int, int);

#ifdef    HAVE_POLL
int Poll(struct pollfd *, unsigned long, int);
#endif

ssize_t Readline(int, void *, size_t);
ssize_t Readn(int, void *, size_t);
ssize_t Recv(int, void *, size_t, int);
ssize_t Recvfrom(int, void *, size_t, int, SA *, socklen_t *);
ssize_t Recvmsg(int, struct msghdr *, int);
int Select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
void Send(int, const void *, size_t, int);
void Sendto(int, const void *, size_t, int, const SA *, socklen_t);
void Sendmsg(int, const struct msghdr *, int);
void Setsockopt(int, int, int, const void *, socklen_t);
void Shutdown(int, int);
int Sockatmark(int);
int Socket(int, int, int);
void Socketpair(int, int, int, int *);
void Writen(int, void *, size_t);

void err_dump(const char *, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);

#endif
