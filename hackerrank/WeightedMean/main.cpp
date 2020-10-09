#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<string> split_string(string);
double getWeightedMean(vector<long> ar, vector<long> weights);

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

  // input and parse weights
  string weights_temp_temp;
  getline(cin, weights_temp_temp);

  vector<string> weights_temp = split_string(weights_temp_temp);

  vector<long> weights(ar_count);

  for (int i = 0; i < ar_count; i++)
  {
      long weight_item = stol(weights_temp[i]);
      weights[i] = weight_item;
  }

  // output results
  //double weightedMean = static_cast<float>(static_cast<int>(getWeightedMean(ar, weights) * 10.0)) / 10.0;
  double weightedMean = getWeightedMean(ar, weights);

  //cout << setprecision(1) << weightedMean << "\n";
  printf("%.1f\n", weightedMean);

  return 0;
}

double getWeightedMean(vector<long> ar, vector<long> weights)
{
  int n = ar.size();
  double weightSum;
  double sum;

  for (int i = 0; i < n; i++)
  {
    sum += ar[i] * weights[i];
  }

  for (int i = 0; i < n; i++)
  {
    weightSum += weights[i];
  }

  return sum / weightSum;
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
