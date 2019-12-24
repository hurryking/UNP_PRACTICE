#include <stdio.h>

void
main()
{
	char * a;
	int* b,c=4,d=5;

	a = "sss";
	b = &d;
	printf("%s %d\n", a, *b);
}