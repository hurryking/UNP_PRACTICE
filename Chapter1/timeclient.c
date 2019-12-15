#include "unp.h"

int
main(int argc, char **argv)
{
	int sockfd, n, counter;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;

	if (argc != 2)
	{
		err_quit("usage:%s <IpAddress>", argv[0]);
	}

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	/*将文本字符串转换成网络字节序的二进制地址*/
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		err_quit("socket error");
	}

	if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
	{
		err_sys("connect error");
	}


	while((n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		counter++;
		recvline[n] = 0; /*字符串结束符*/
		if (fputs(recvline, stdout) == EOF)
		{
			err_sys("fputs error");
		}
	}

	if (n < 0)
	{
		err_sys("read error");
	}
	printf("%d\n", counter);
	exit(0);
}
