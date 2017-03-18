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
int dp[28][280];
int pos,len,prevsum;
string a;
int solve(int pos,int prevsum)
{
	int count=0;
	int sum=0;
	if(pos==len)
		return 1;
	if(dp[pos][prevsum]!=-1)
		return dp[pos][prevsum];
	dp[pos][prevsum]=0;
	for(int i=pos;i<len;i++)
	{
		sum+=(a[i]-'0');
		if(sum>=prevsum)
		{
			count+=solve(i+1,sum);
		}
	}
	dp[pos][prevsum]=count;
	return count;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int c=1;
	cin>>a;
	while(a[0]!='b')
	{
		memset(dp,-1,sizeof(dp));
		len=a.length();
		cout<<c<<". "<<solve(0,0)<<"\n";
		cin>>a;
		c++;
	}
	return 0;
}
