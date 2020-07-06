#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

void compute_prefix(string& p, vector<int>& s) 
{
  int border = 0;

  for (int i=1; i<p.size(); i++) 
  {
    while (border>0 && p[i] != p[border]) 
    {
      border= s[border-1];
    }

    if (p[i]== p[border]) 
    {
      border++;
      s[i] = border;
    }

    if (border == 0) 
    {
      s[i] = 0;
    }
  }
}
 

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) 
{
  vector<int> result;
  string p = pattern+'$'+text;
  vector<int> s(p.size());

  compute_prefix(p,s);

  for (int i=pattern.size()+1; i <p.size(); i++) 
  {
    if(s[i]==pattern.size()) 
    {
      result.push_back(i-2*pattern.size());
    }
  }
  
  return result;
}



int main() 
{
  IOS;
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i <result.size(); ++i) 
  {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}

