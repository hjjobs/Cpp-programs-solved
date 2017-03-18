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
		int n,i,c=0;
		ll temp=LLONG_MIN;
		int arr[100005]={0};
		ll a[100005]={0};
		ll b[100005]={0};
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
			if(arr[i]<0)
				c++;
		}
		if(c==n)
		{
			ll ans=LLONG_MIN;
			for(i=1;i<=n;i++)
			{
				ans=max(arr[i],ans);
			}
			cout<<ans<<"\n";
		}
		else
		{
			a[0]=0;
			for(i=1;i<=n;i++)
			{
				a[i]=max(arr[i],(a[i-1]+arr[i]));
			}
			b[0]=0;
			b[1]=arr[1];
			for(i=2;i<=n;i++)
			{
				b[i]=max((arr[i]+a[i-2]),arr[i]+b[i-1]);
			}
			for(i=1;i<=n;i++)
			{
				temp=max(temp,max(a[i],b[i]));
			}
			cout<<temp<<"\n";
		}
	}
	return 0;
}
