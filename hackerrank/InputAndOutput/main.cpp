#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int size = 3;
  int sum = 0;

  vector<int> ar(size);

  for (int i = 0; i < size; i++)
  {
    cin >> ar[i];
  }

  for (int i = 0; i < size; i++)
  {
    sum += ar[i];
  }
    
  cout << sum << endl;

  return 0;
}
