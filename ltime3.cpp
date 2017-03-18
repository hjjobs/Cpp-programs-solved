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
bool func(ll val,ll *p,ll *q)
{
	ll cnt2=val/2;
	ll cnt1=val%2;
	while(cnt2>*q)
	{
		cnt1+=2;
		cnt2-=1;
	}
	if(cnt1>*p)
	{
		return false;
	}
	*q-=cnt2;
	*p-=cnt1;
	return true;
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
		ll n,p,q;
		int i;
		cin>>n>>p>>q;
		ll arr[n+1];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		ll ans=0;
		for(i=0;i<n;i++)
		{
			if(func(arr[i],&p,&q))
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
