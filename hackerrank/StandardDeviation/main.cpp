#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double getMean(vector<long> ar);

int main()
{
  // input size
  int n;
  cin >> n;

  // input array
  vector<long> ar(n);

  for (int i = 0; i < n; i++)
  {
    cin >> ar[i];
  }

  // find standard deviation
  double deviation, sum;
  double mean = getMean(ar);
  
  // sum of squared distances
  for (int i = 0; i < n; i++)
  {
    sum += pow(ar[i] - mean, 2);
  }

  deviation = sqrt(sum / n);

  // print standard deviation
  printf("%.1f\n", deviation);

  return 0;
}

double getMean(vector<long> ar)
{
  int n = ar.size();
  double sum;

  for (int i = 0; i < n; i++)
  {
    sum += ar[i];
  }

  return sum / n;
}