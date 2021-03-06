#include "unp.h"

int
main(int argc, char **argv)
{
	union {
		short s;
		char c[sizeof(short)];
	} un;
	un.s = 0x0102;
	printf("%s: ", CPU_VENDOR_OS);
	if (sizeof(short) == 2)
	{
		if (un.c[0] == 1)
		{
			printf("big-endian\n");
		} else if (un.c[0] == 2)
		{
			printf("little-endian\n");
		} else
		{
			printf("unkown\n");
		}
	} else
	{
		printf("sizeof(short) = %lu\n", sizeof(short));
	}

	exit(0);
}