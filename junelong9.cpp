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
vector < int > a[200005];
int arr[200005];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int n,e,t1,t2,i,j;
	cin>>n>>e;
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=0;i<e;i++)
	{
		cin>>t1>>t2;
		a[t1].pb(t2);
		a[t2].pb(t1);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<a[i].size();j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
