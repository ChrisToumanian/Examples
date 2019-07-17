#include <stdio.h>
#include "math.h"

int main()
{
	int a;
	int b;
	int c;
	printf("Choose two numbers to add.\n");
	scanf("%d%d", &a, &b);
	c = Add(a, b);
	printf("%d%s", c, "\n");
	return 0;
}
