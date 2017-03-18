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
int arr[1010][1010];
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
		int i,j,n,m,s;
		int arr1[1005]={0};
		memset(arr,0,sizeof(arr));
		cin>>n>>m>>s;
		arr[0][s]=1;
		for(i=1;i<=m;i++)
			cin>>arr1[i];
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(arr[i-1][j]>0)
				{
					if(j+arr1[i]<=n)
					{
						arr[i][j+arr1[i]]=(arr[i][j+arr1[i]]+(arr[i-1][j])%mod)%mod;
					}
					if(j-arr1[i]>=1)
					{
						arr[i][j-arr1[i]]=(arr[i][j-arr1[i]]+(arr[i-1][j])%mod)%mod;
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
				cout<<arr[m][i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
