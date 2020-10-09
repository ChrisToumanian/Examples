#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, int> tags;
vector<string> queries;

int main()
{
  int n, q, value;
  string tag;

  // input number of tags and queries
  cin >> n >> q;
  cin.ignore();

  // input tags
  while (n--)
  {
    int i = 0;
    string line;
    
    getline(cin, line);
    
    while (line[i] != '=')
      i++;

    tag = line.substr(0, line.size() - (line.size() - i));
    value = stoi(line.substr(i + 1, line.size()));
    tags[tag] = value;
    cout << "Inputted " << tag << " with value of " << value << endl;
  }

  // input queries
  while (q--)
  {
    string line;
    
    getline(cin, line);
    queries.push_back(line);
  }

  // print query answers
  for (int i = 0; i < queries.size(); i++)
  {
    cout << queries[i] << ": " << tags[queries[i]] << endl;
  }
}
