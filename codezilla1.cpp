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
		int n,i,j;
		cin>>n;
		ll arr[100005];
		for(i=0;i<n;i++)
			cin>>arr[i];
		int flag=0;
		ll mini=arr[0];
		for(i=0;i<n-1;i++)
		{
			if(mini<=arr[i+1])
			{
				flag=1;
				break;
			}
			else
			{
				mini=arr[i+1];
			}
		}
		if(flag==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
