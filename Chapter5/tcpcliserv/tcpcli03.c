#include "unp.h"

void
sig_pipe(int signo)
{
	printf("SIGPIPE received\n");
	return;
}

int
main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	if (argc != 2)
		err_quit("usage: %s <IPaddress>", argv[0]);

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr); /*字符串格式转换为二进制格式*/

	Signal(SIGPIPE, sig_pipe);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	
	str_cli(stdin, sockfd);

	exit(0);
}