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
		int n,i;
		pair <double,double> arr[100005];
		double a,b,c,d;
		cin>>n;
		int xl,yl;
		cin>>xl>>yl;
		for(i=0;i<n;i++)
		{
			cin>>a>>b>>c>>d;
			double xr1=-(yl/(b-yl))*(a-xl)+xl;
			double xr2=-(yl/(d-yl))*(c-xl)+xl;
			arr[i].first=min(xr1,xr2);
			arr[i].second=max(xr1,xr2);
		}
		sort(arr,arr+n);
		if(n==0)
		{
			cout<<1<<"\n";
		}
		else if(n==1)
		{
			cout<<2<<"\n";
		}
		else
		{
			int c=1;
			double mini=arr[0].first;
			double maxi=arr[0].second;
			for(i=1;i<n;i++)
			{
				if(arr[i].first<=maxi&&arr[i].second>=mini)
				{
					maxi=max(maxi,arr[i].second);
				}
				else
				{
					c++;
					mini=arr[i].first;
					maxi=arr[i].second;
				}
			}
			c++;
			cout<<c<<"\n";
		}
	}
	return 0;
}
