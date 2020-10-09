#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

void read_query(vector<int>& v)
{
	vector<int> args;
	int x;
	string str;

	getline(cin, str);
	istringstream ss(str);

  while (!ss.eof()) {
		ss >> x;
		args.push_back(x);
	}

	if (args.size() == 1)
	{
		v.erase(v.begin() + args[0] - 1);
	}
	else if (args.size() == 2)
	{
		v.erase(v.begin() + args[0] - 1, v.begin() + args[1] - 1);
	}
}

int main()
{
	int n, x;
	vector<int> v;

	cin >> n;

	// input vector
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	// read 2 queries
	cin.ignore(256, '\n');
	read_query(v);
	read_query(v);

  /* // remove item
  int a, b;
  cin >> a;
  v.erase(v.begin() + a - 1);

  // remove range
  cin >> a >> b;
  v.erase(v.begin() + a - 1, v.begin() + b - 1); */

	// print size of vector
	cout << v.size() << endl;

	// print vector
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}