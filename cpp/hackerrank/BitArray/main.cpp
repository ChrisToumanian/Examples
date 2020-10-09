#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> a;
  vector<int> b;
  int n, s, p, q;

  cin >> n >> s >> p >> q;

  a.push_back(s);

  for (int i = 1; i < n; i++)
  {
    int x = a[i - 1] * p + q;
    a.push_back(x);
    
    bool found = false;
    for (int j = 0; j < a.size(); j++)
    {
      cout << a[j] << " , " << x << endl;
      if (a[j] == x)
        found = true;
    }

    if (!found)
      b.push_back(x);
  }

  cout << b.size();

  return 0;
}
