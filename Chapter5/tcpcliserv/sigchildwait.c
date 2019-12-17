#include "unp.h"

void
sig_child(int singo)
{
	pid_t pid;
	int stat;

	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child %d terminated stat %d\n", pid, stat);
	return;
}