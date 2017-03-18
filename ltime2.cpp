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
ll gcd(ll a, ll b) {
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
		ll arr[50005];
		int n,i;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		ll mini=LLONG_MAX;
		for(i=0;i<n-1;i++)
		{
			mini=min(mini,(arr[i+1]-arr[i]));
		}
		cout<<mini<<"\n";
	}
	return 0;
}
