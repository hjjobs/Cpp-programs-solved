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
ll arr1[2005],arr2[2005];
ll dp[2005][2005];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	ll s,n,i,j;
	cin>>s>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr1[i]>>arr2[i];
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=s;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(arr1[i-1]<=j)
				dp[i][j]=max(dp[i-1][j],arr2[i-1]+dp[i-1][j-arr1[i-1]]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][s];
	return 0;
}
