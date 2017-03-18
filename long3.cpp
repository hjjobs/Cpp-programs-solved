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
		ll n,m;
		cin>>n>>m;
		if(n==1||m==1)
		{
			if(n==2||m==2)
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
		else
		{
			if((n*m)%2==0)
				cout<<"Yes\n";
			else
				cout<<"No\n";
			}
	}
	return 0;
}
