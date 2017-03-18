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
#define PI acos(-1)
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
		cin>>n;
		ll arr[100005];
		ll temp[100005];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			temp[i]=arr[i]/2;
		}
		//sort(arr,arr+n);
		ll med=0;
		int c=0;
		if(n%2==0)
		{
			med=(arr[n/2]+arr[(n/2)-1])/2;
			cout<<med<<" ";
		}
		else
		{
			med=arr[n/2];
		}
		for(i=0;i<n;i++)
		{
			if(arr[i]>med)
			{
				while(arr[i]>med)
				{
					arr[i]=arr[i]/2;
					c++;
				}
			}
			if(arr[i]<med)
			{
				while(arr[i]!=med)
				{
					arr[i]=arr[i]+1;
					c++;
				}
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}
