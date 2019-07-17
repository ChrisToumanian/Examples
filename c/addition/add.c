#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;

	printf("Choose two numbers to add.\n");
	scanf("%d%d", &a, &b);
	c = Add(a, b);
	printf("%d%s", c, "\n");
	return 0;
}
