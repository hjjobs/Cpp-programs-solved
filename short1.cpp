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
ll s(ll n)
{
	ll sum=0;
	ll digit;
	while(n)
	{
		digit=n%10;
		sum+=digit;
		n=n/10;
	}
	return sum;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll n,i,count=0;
	cin>>n;
	for(i=max(0,n-1000);i<=n;i++)
	{
		if((i+s(i)+s(s(i)))==n)
			count++;
	}
	cout<<count<<"\n";
	return 0;
}
