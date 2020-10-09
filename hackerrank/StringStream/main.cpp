#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str)
{
  vector<int> integers;
  stringstream ss(str);
  int tmp;
  char ch;

  ss >> tmp;
  integers.push_back(tmp);
  
  while (ss >> ch >> tmp)
  {
    integers.push_back(tmp);
  }
  
  return integers;
}

int main()
{
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);

  for(int i = 0; i < integers.size(); i++)
  {
    cout << integers[i] << "\n";
  }

  return 0;
}
