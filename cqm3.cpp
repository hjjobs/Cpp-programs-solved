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
	int n,i;
	pair <ll,ll> p[100005];
	ll temp[100005];
	cin>>n;
	ll a,b;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		p[i].first=a;
		p[i].second=b;
	}
	sort(p,p+n);
	temp[0]=p[0].second;
	//cout<<temp[0]<<"\n";
	for(i=1;i<n;i++)
	{
		temp[i]=temp[i-1]+p[i].second;
		//cout<<i<<" "<<temp[i]<<"\n";
	}
	ll t1;
	ll ans=0;
	for(i=n-1;i>0;i--)
	{
		t1=abs((p[i].second*i)-(temp[i-1]))*(p[i].first);
		//cout<<t1<<" ";
		ans=ans+t1;
		//cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
