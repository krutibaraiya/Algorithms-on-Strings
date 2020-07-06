#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long
 
const int N = 1e5 + 5;

string BWT(const string& text) 
{
	string result="";
	int n= text.length();
	vector<string> v(n);

	for(int i=0; i<n ;i++)
	{
		v[i]= text.substr(i)+ text.substr(0,i);
	}

	sort(v.begin(),v.end());

	for(int i=0; i<v.size();i++)
	{
		result+=v[i][v.size()-1];
	}

	return result;

  
}

int main() 
{
	IOS;
	string text;
  	cin >> text;
  	cout << BWT(text) << endl;

  	return 0;
}

  



