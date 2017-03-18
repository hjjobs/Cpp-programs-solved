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
		int n,k,i;
		cin>>n>>k;
		if((n/2)<k)
		{
			cout<<"-1\n";
		}
		else
		{
			if(k==1)
			{
				if(n%2==0)
				{
					for(i=1;i<=n;i++)
					{
						if(i%2==0)
							cout<<i-1<<" ";
						else
						{
							cout<<i+1<<" ";
						}
					}
				}
				else
				{
					for(i=1;i<=n-3;i++)
					{
						if(i%2==0)
							cout<<i-1<<" ";  
						else
						{
							cout<<i+1<<" ";
						}
					}
					cout<<n-1<<" ";
					cout<<n<<" ";
					cout<<n-2<<" ";
				}
			}
			else if(k==0)
			{
				for(i=1;i<=n;i++)
					cout<<i<<" ";
			}
			else
			{
				for(i=k+1;i<=n;i++)
				{
					cout<<i<<" ";
				}
				for(i=1;i<=k;i++)
				{
					cout<<i<<" ";
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}
