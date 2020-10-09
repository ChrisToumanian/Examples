#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;

  int** a = new int*[n]();
  int answers[q];

  // fill arrays
  for (int i = 0; i < n; i++)
  {
    int k; // k elements in referenced array

    cin >> k;

    int* arr = new int[k]();

    for (int j = 0; j < k; j++)
    {
      cin >> arr[j];
    }

    a[i] = arr;
  }

  // perform queries
  for (int l = 0; l < q; l++)
  {
    int i, j;

    cin >> i; // ith element of arr
    cin >> j; // jth element of referenced array

    answers[l] = a[i][j];
  }

  // print answers
  for (int i = 0; i < q; i++)
    cout << answers[i] << endl;
  
  return 0;
}
