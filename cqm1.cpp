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
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		int mini=INT_MAX;
		int arr[1005];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			mini=min(mini,arr[i]);
		}
		if(n==1)
			cout<<0<<"\n";
		else
		{
			cout<<mini*(n-1)<<"\n";
		}
	}
	return 0;
}
