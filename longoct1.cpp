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
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,c;
		cin>>n>>m>>c;
		ll an=min(n,m);
		ll an1=max(n,m);
		ll cnt=0;
		for(int i=1;i<=an;i++)
		{
			if(c%i==0&&(c/i<=an1))
			{
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
