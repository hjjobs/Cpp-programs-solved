#include <bits/stdc++.h>
 
using namespace std;
 
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		ll m;
		ll a[100001]={0};
		ll b[100001]={0};
		scanf("%d",&n);
		scanf("%d",&x);
		scanf("%lld",&m);
		scanf("%lld"&a[1]);
		b[1]=m*a[1];
		for(i=2;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			b[i]=m*(a[i]+a[i-1])%mod;
		}
		for(i=1;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
	}
	return 0;
}