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
int isprime[1005];
void sieve()
{
	isprime[0]=0;
	isprime[1]=0;
	for(int i=2;i<=sqrt(1000);i++)
	{
		if(isprime[i]==1)
		{
			for(int j=i*i;j<=1000;j=j+i)
			{
				isprime[j]=0;
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	for(int i=0;i<1001;i++)
		isprime[i]=1;
	sieve();
	int t,i,j;
	cin>>t;
	while(t--)
	{
		int n,i;
		int maxi=INT_MIN;
		cin>>n;
		int arr[1005];
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<n;i++)
		{
			if(isprime[arr[i]]==1)
			{
				//maxi=max(maxi,arr[i]*arr[i]);
				for(j=i;j<n;j++)
				{
					if(isprime[arr[j]]==1)
					{
						maxi=max(maxi,arr[i]*arr[j]);
					}
				}
			}
		}
		if(maxi==INT_MIN)
		{
			cout<<-1<<"\n";
		}
		else
		{
			cout<<maxi<<"\n";
		}
	}
	return 0;
}
