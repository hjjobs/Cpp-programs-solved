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
	int n,i,j;
	cin>>n;
	string a[1005];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int vis[1005]={0};
	int c=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].substr(0,a[i].size()-2)==a[j].substr(0,a[j].size()-2)&&vis[j]==0)
			{
				if(a[i][a[i].size()-2]=='k'&&a[i][a[i].size()-1]=='a'&&a[j][a[j].size()-2]=='k'&&a[j][a[j].size()-1]=='i')
				{
					vis[j]=1;
					c++;
					break;
				}
				else if(a[j][a[j].size()-2]=='k'&&a[j][a[j].size()-1]=='a'&&a[i][a[i].size()-2]=='k'&&a[i][a[i].size()-1]=='i')
				{
					vis[j]=1;
					c++;
					break;
				}
			}
		}
	}
	cout<<c<<"\n";
	return 0;
}
