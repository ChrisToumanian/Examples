#include <iostream>

using namespace std;

int map[] = { 1, 2, 3, 4, 5};

void printElement(int *map, int element)
{
	cout << map[element] << endl;
}

void printElement2(int map[], int element)
{
	cout << map[element] << endl;
	map[element] = 22;
}

int &getRef(int a)
{
	static int b = a;
	return b;
}

int main()
{
	// References act as an alias to another object, and is used like a normal object. 
	// Pointers hold an address, must be given an address with & and return an address unless dereferenced with *.

	// Use references wherever you can, pointers wherever you must.
	// Pointers are more dangerous because they point to specific memory addresses, where references point to specific objects.
	// References cannot be null, pointers can be nullptr, which goes into undefined-behavior-land.
	// Performance is the same.
	// Use references when the parameter must refer an existing object and pointers when a NULL value is ok.

	// Usage: references are most often used on the skin of an object, the public interface, whereas pointers are used on the inside.
	// References are less explicit and used like regular values, which is an asset in OOP. Write code in the language of the problem, not the machine and hide information.

	printElement(map, 0);
	printElement2(map, 0);

	cout << map[0] << endl;

	int &x = getRef(3);
	int ox = 2;
	x = ox;			// assign reference x with another variable

	int &rx = x;			// reference to reference of x
	cout << rx << endl;		// prints value of x

	cout << x << endl; 		// prints value of x
	cout << &x << endl;		// address of x

	int y = 4;
	int *p = &y;			// assigns address of y to pointer

	cout << &y << endl;		// prints address of y
	cout << p << endl;		// address of y is value of p
	cout << &p << endl;		// address of pointer
	cout << *p << endl;		// value of pointer, dereferenced
}

