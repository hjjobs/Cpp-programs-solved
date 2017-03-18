#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
#define pb push_back
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
		int n,m,i,j;
		int dp[2][205][205];
		memset(dp,0,sizeof(dp));
		char temp;
		cin>>n>>m;
		int arr[n+5][m+5];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>temp;
				if(temp=='T')
					arr[i][j]=2;
				else if(temp=='0')
					arr[i][j]=1;
				else
					arr[i][j]=0;
			}
		}
		for(i=n;i>0;i--)
		{
			for(j=1;j<=m;j++)
			{
				if(arr[i][j])
					dp[0][i][j]=max(dp[0][i][j-1],dp[1][i+1][j])+arr[i][j]-1;
			}
			for(j=m;j>0;j--)
			{
				if(arr[i][j])
					dp[1][i][j]=max(dp[1][i][j+1],dp[0][i+1][j])+arr[i][j]-1;
			}
		}
		cout<<dp[1][1][1]<<"\n";
	}
	return 0;
}
