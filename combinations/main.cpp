#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> combo;

void print(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	  	cout << vec[i] << " ";
	cout << endl;
}

void shift(vector<int> v, int offset, int n)
{
  	for (int i = offset; i < v.size() - n; i++)
	{
		v.push_back(v[i]);
		v.erase(v.begin() + offset);
	}
}

void recombine(int offset, int n)
{
	for (int i = 0; i < n; i++)
	{
		
	}

	shift(vec, 1, n - 1);
	print(vec);
}

int getTotalCombinations(vector<int> vec)
{
  	int n = vec.size();
  	int k = n;

	for (int i = 1; i < n; i++)
	  	k *= n - i;
	
	return k;
}

int main()
{
	int n, i;
	cin >> n;

	while (n--)
	{
		cin >> i;
		vec.push_back(i);
	}

	cout << endl;
	print(vec);

	cout << "Total combinations: " << getTotalCombinations(vec) << endl << endl;

	recombine(0, vec.size());
}
