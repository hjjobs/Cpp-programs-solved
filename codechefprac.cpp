#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
#define pb push_back
#define bp(x) __builtin_popcount(x)
typedef long long int ll;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int i;
		string x,y;
		cin>>x>>y;
		for(i=0;i<x.length();i++)
		{
			if(x[i]==y[i]&&x[i]=='W')
				cout<<"B";
			else if(x[i]==y[i]&&x[i]=='B')
				cout<<"W";
			else if(x[i]!=y[i])
				cout<<"B";
		}
		cout<<"\n";
	}
	return 0;
}
