//#include <cmath>
//#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
//#include <algorithm>

using namespace std;

int main()
{
  // input size
  int n;
  cin >> n;

  // input array
  vector<int> ar(n);

  for (int i = 0; i < n; i++)
  {
    cin >> ar[i];
  }

  // print size and array
  cout << n << endl;

  for (int i = 0; i < n; i++)
    cout << setprecision(0) << ar[i] << endl;

  return 0;
}
