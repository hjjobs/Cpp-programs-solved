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
	ll n,q,i,temp;
	ll mini=LLONG_MAX;
	ll maxi=LLONG_MIN;
	ll arr[100005]={0};
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		mini=min(arr[i],mini);
		maxi=max(arr[i],maxi);
	}
	for(i=0;i<q;i++)
	{
		cin>>temp;
		if(temp>=mini&&temp<=maxi)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}

	}
	return 0;
}
