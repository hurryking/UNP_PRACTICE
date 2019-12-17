#include "unp.h"


void
str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		// Writen(sockfd, sendline, 1);
		// sleep(1);
		Writen(sockfd, sendline, strlen(sendline));

		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		Fputs(recvline, stdout);
	}
}

int
main(int argc, char **argv)
{
	int sockfd[5], i;
	struct sockaddr_in servaddr;
	if (argc != 2)
		err_quit("usage: %s <IPaddress>", argv[0]);

	for (i = 0; i < 1; i++)
	{
		sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr); /*字符串格式转换为二进制格式*/

		Connect(sockfd[i], (SA *) &servaddr, sizeof(servaddr));
	}
	
	str_cli(stdin, sockfd[0]);
	exit(0);
}