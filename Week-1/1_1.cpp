#include<bits/stdc++.h>
using namespace std;

 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;



typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) 
{
  trie t;
  edges root;
  t.push_back(root);

  int nodeNum=0;

  for(int i=0; i<patterns.size();i++)
  {
    int currNode = 0;

    for(int j=0; j<patterns[i].length();j++)
    {
      char currSymbol = patterns[i][j];

      if(t[currNode].find(currSymbol)!=t[currNode].end())
      {
          currNode = t[currNode][currSymbol];
      }
      else
      {
          t[currNode][currSymbol] = ++nodeNum;
          edges temp;
          t.push_back(temp);
          currNode = nodeNum;
      }
    }
  }
  return t;
}

int32_t main() 
{
  IOS;
  size_t n;
  cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) 
  {
    string s;
    cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) 
  {
    for (const auto & j : t[i]) 
    {
      cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}


