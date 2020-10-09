#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split_string(string);
double getMean(vector<long> ar);
double getMedian(vector<long> ar);
long getMode(vector<long> ar);
void printArray(vector<long> ar);

int main()
{
  // input length of array
  int ar_count;
  cin >> ar_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // input and parse long array
  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split_string(ar_temp_temp);

  vector<long> ar(ar_count);

  for (int i = 0; i < ar_count; i++)
  {
    long ar_item = stol(ar_temp[i]);

    ar[i] = ar_item;
  }

  // output results
  cout << getMean(ar) << "\n";
  cout << getMedian(ar) << "\n";
  cout << getMode(ar) << "\n";

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

long getMode(vector<long> ar)
{
  long mode = 0;
  int count = 0;
  int n = ar.size();

  if (n != 0)
  {
    mode = ar[0];

    sort(ar.begin(), ar.end());

    for (int i = 0; i < n; i++)
    {
      int tempCount = 1;
      for (int j = 0; j < n; j++)
      {
        if (ar[j] == ar[i])
          tempCount++;
      }

      if (tempCount > count)
      {
        mode = ar[i];
        count = tempCount;
      }
    }
  }

  return mode;
}

void printArray(vector<long> ar)
{
  for (int i = 0; i < ar.size(); i++)
    cout << ar[i] << endl;
}

vector<string> split_string(string input_string)
{
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y)
  {
      return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ')
  {
      input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos)
  {
    splits.push_back(input_string.substr(i, pos - i));
    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}