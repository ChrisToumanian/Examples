#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double getFirstQuartile(vector<long> ar);
double getThirdQuartile(vector<long> ar);
double getMedian(vector<long> ar);
int getMedianElement(vector<long> ar);

int main()
{
  // input size
  int n;
  cin >> n;

  // input array
  vector<long> elem(n);

  for (int i = 0; i < n; i++)
  {
    cin >> elem[i];
  }

  // input frequency
  vector<long> freq(n);

  for (int i = 0; i < n; i++)
  {
    cin >> freq[i];
  }

  // expand array
  vector<long> ar;

  for (int i = 0; i < n; i++)
  {
    int frequency = freq[i];
    for (int j = 0; j < frequency; j++)
      ar.push_back(elem[i]);
  }

  // sort array
  sort(ar.begin(), ar.end());

  /* for (int i = 0; i < ar.size(); i++)
  {
    cout << ar[i];
    cout << " ";
  }
  cout << endl; */

  // get 1st and 3rd quartiles
  double q1 = getFirstQuartile(ar);
  double q3 = getThirdQuartile(ar);

  // find interquartile range
  //cout << setprecision(1) << q3 - q1 << endl;
  printf("%.1f\n", (double) q3 - q1);

  return 0;
}

double getFirstQuartile(vector<long> ar)
{
  vector<long> ar1;

  if (ar.size() % 2 == 0)
    for (int i = 0; i < getMedianElement(ar) + 1; i++)
      ar1.push_back(ar[i]);
  else
    for (int i = 0; i < getMedianElement(ar); i++)
      ar1.push_back(ar[i]);

  return getMedian(ar1);
}

double getThirdQuartile(vector<long> ar)
{
  vector<long> ar3;

  for (int i = getMedianElement(ar) + 1; i < ar.size(); i++)
    ar3.push_back(ar[i]);

  return getMedian(ar3);
}

double getMedian(vector<long> ar)
{
  int n = ar.size();

  if (n != 0)
  {
    sort(ar.begin(), ar.end());

    if (n % 2 == 0)
    {
      return (double) (ar[n / 2 - 1] + ar[n / 2]) / 2;
    }
    else
    {
      return (double) ar[n / 2];
    }
  }

  return 0;
}

int getMedianElement(vector<long> ar)
{
  int n = ar.size();

  if (n != 0)
  {
    sort(ar.begin(), ar.end());

    if (n % 2 == 0)
    {
      return (n / 2) - 1;
    }
    else
    {
      return n / 2;
    }
  }
  
  return 0;
}
