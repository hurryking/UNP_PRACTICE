#include "unp.h"

void
sig_child(int singo)
{
	pid_t pid;
	int stat;

	pid = wait(&stat);
	printf("child %d terminated stat %d\n", pid, stat);
	return;
}