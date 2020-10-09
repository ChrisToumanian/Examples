#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n, q, x;
  bool found;
  
  cin >> n;
  vector<int> numbers;

  for (int i = 0; i < n; i++)
  {
    cin >> x;
    numbers.push_back(x);
  }

  cin >> q;

  for (int i = 0; i < q; i++)
  {
    cin >> x;

    found = false;

    auto it = lower_bound(numbers.begin(), numbers.end(), x);

    if (*it == x)
      cout << "Yes " << it - numbers.begin() + 1 << endl;
    else
      cout << "No " << it - numbers.begin() + 1 << endl;

    /* for (int j = 0; j < n; j++)
    {
      if (numbers[j] > x)
      {
        cout << "No " << j + 1 << endl;
        break;
      }
      else if (x == numbers[j])
      {
        cout << "Yes " << j + 1 << endl;
        found = true;
        break;
      }
    } */
  }

  return 0;
}
