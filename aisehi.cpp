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
		int arr[100005]={0};
		int temp[100005]={0};
		cin>>n;
		int ce=0,co=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]%2==0)
			{
				temp[i]=1;
				ce++;
			}
			else
			{
				temp[i]=0;
				co++;
			}
		}
		int mark1=0;
		int mark2=0;
		if(co%2==0)
		{
			cout<<n<<"\n";
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(temp[i]==0)
				{
					mark1=i;
					break;
				}
			}
			for(i=n-1;i>=0;i--)
			{
				if(temp[i]==0)
				{
					mark2=i;
					break;
				}
			}
			cout<<max(mark1,max(mark2,max((n-mark1-1),(n-mark2-1))))<<"\n";
		}
	}
	return 0;
}
