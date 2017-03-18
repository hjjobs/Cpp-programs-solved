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
int arr[2005];
int dp[2005][2005];
int n;
int solve(int start,int end)
{
	if(start>end)
		return 0;
	int year=n-(end-start+1)+1;
	if(dp[start][end])
		return dp[start][end];
	dp[start][end]=max(solve(start+1,end)+arr[start]*year,solve(start,end-1)+arr[end]*year);
	return dp[start][end];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<solve(0,n-1)<<"\n";
	return 0;
}
