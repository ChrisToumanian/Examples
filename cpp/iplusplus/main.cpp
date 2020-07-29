#include <iostream>

int main()
{
	int i = 1;
	int x = ++i + ++i;

	std::cout << x << std::endl; // prints 6

	return 0;
}
