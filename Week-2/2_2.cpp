#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

string InverseBWT(const string& bwt) 
{
	string text = "";
	int n= bwt.size();
	vector<pair<char,int>> v1(n);

	for(int i=0; i<n; i++)
	{
		v1[i]= make_pair(bwt[i],i);
	}

	sort(v1.begin(),v1.end());

	pair<char,int> letter=v1[0];

	for(int i=0; i<n; i++)
	{
		letter=v1[letter.second];
		text+=letter.first;
	}

  
	return text;

}

int32_t main() 
{
	IOS;
  	string bwt;
  	cin >> bwt;
  	cout << InverseBWT(bwt) << endl;
  	return 0;
}



