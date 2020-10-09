#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void parseTags();
void handleQueries();

struct Tag {
  string name;
  string attribute;
  string value;
};

vector<string> hrml;
vector<string> queries;
vector<Tag> tags;

int main()
{
  int n, q; // N "HRML" lines, Q queries
  int i = 0;
  cin >> n >> q;

  // input lines
  for (int i = 0; i <= n; i++)
  {
    string line, word;
    getline(cin, line);
    stringstream data(line);

    while (std::getline(data, word, ' '))
      hrml.push_back(word);
  }

  // input queries
  for (int i = 0; i < q; i++)
  {
    string line, word;
    getline(cin, line);
    queries.push_back(line);
  }

  parseTags();
  handleQueries();

  return 0;
}

void parseTags()
{
  vector<string> hierarchy;

  for (int i = 0; i < hrml.size(); i++)
  {
    string word = hrml[i];

    if (word[0] == '<' && word[1] != '/') // opening tag
    {
      struct Tag tag;
      tag.name = word.substr(1, word.length() - 1);
      tags.push_back(tag);
      hierarchy.push_back(tag.name);
    }
    else if (word[0] == '<' && word[1] == '/') // closing tag
    {
      hierarchy.pop_back();
    }
    else if (word == "=") // set attribute
    {
      string attribute = hrml[i - 1];
      string value = hrml[i + 1].substr(1, hrml[i + 1].size() - 3);

      for (int i = 0; i < tags.size(); i++)
      {
        if (tags[i].name == hierarchy.back())
        {
          tags[i].attribute = attribute;
          tags[i].value = value;
        }
      }
    }
  }
}

void handleQueries()
{
  for (int i = 0; i < queries.size(); i++)
  {
    string query = queries[i];
    string name, attribute, value;
    int period = 0;

    for (int j = 0; j < query.size(); j++)
    {
      if (query[j] == '.')
        period = j;

      // get name and attribute from query
      if (query[j] == '~')
      {
        attribute = query.substr(j + 1, query.size() - j);
        
        if (period == 0)
        {
          name = query.substr(0, j);
        }
        else
        {
          name = query.substr(period + 1, query.size() - (query.size() - j) - period - 1);
        }
      }
    }

    // get value from tags
    for (int i = 0; i < tags.size(); i++)
    {
      if (tags[i].name == name)
      {
        if (tags[i].attribute == attribute)
          cout << tags[i].value << endl;
        else 
          cout << "Not Found!" << endl;
      }
    }
  }
}