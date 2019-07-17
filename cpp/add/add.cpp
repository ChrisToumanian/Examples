#include <iostream>

using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	int a;
	int b;
	int c;

	cout << "Which to numbers would you like to add?" << endl;
	cin >> a;
	cin >> b;
	c = Add(a, b);
	cout << c << endl;

	return 0;
}
