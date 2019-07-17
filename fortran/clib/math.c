int add(int *a, int *b, int *c)
{
	*c = *a + *b;
	return 0;
}

int subtract(int* a, int* b, int* c)
{
	(*c) = (*a) - (*b);
	return 0;
}

int multiply(int* a, int* b)
{
	int c = (*a) * (*b);
	return c;
}

double divide(int* a, int* b)
{
	int c = (*a) * (*b);
	return c;
}