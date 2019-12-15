#include "unp.h"
#include <time.h>

int
main(int argc, char *argv[])
{
	pid_t pid;
	int listenfd, connfd;
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;
	char buff[MAXLINE];
	time_t ticks;
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);

	for (;;)
	{
		len = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *)&cliaddr, &len);
		if ((pid = Fork()) == 0)
		{
			Close(listenfd); /*子进程不监听请求让父进程监听*/
			printf("connection from %s, port %d\n", 
			Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
			ntohs(cliaddr.sin_port));

			ticks = time(NULL);
			snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
			Write(connfd, buff, strlen(buff));
			Close(connfd);	/*处理完成客户端的请求后关闭它*/
			exit(0);
		}
		
		Close(connfd); /*父进程不处理请求，只负责监听*/
	}
}