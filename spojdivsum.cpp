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
		ll sum=0;
		int n,i;
		cin>>n;
		int temp=sqrt(n);
		for(i=1;i<=temp;i++)
		{
			if(n%i==0)
			{
				if(i==n/i)
            		sum+=i;
            	else
	            	sum+=i+n/i;
			}
		}
		cout<<sum-n<<"\n";
	}
	return 0;
}
