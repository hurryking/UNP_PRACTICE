#include <stdio.h>

int power(int, int);

int
main(int argc, char const *argv[])
{
	printf("%d\n", power(2, 3));
	return 0;
}

int
power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p = p * base;

	return p;
}