#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double getFirstQuartile(vector<long> ar);
double getSecondQuartile(vector<long> ar);
double getThirdQuartile(vector<long> ar);
double getMedian(vector<long> ar);
int getMedianElement(vector<long> ar);

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

  // sort array
  sort(ar.begin(), ar.end());

  // print quartiles
  cout << getFirstQuartile(ar) << endl;
  cout << getSecondQuartile(ar) << endl;
  cout << getThirdQuartile(ar) << endl;

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

double getSecondQuartile(vector<long> ar)
{
  return getMedian(ar);
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