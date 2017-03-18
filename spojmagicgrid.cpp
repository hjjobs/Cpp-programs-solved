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
		int r,c,i,j;
		int arr[505][505];
		memset(arr,0,sizeof(arr));
		cin>>r>>c;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>arr[i][j];
			}
		}
		arr[r-1][c-1]=1;
		for(i=c-2;i>=0;i--)
		{
			arr[r-1][i]=arr[r-1][i+1]-arr[r-1][i];
			if(arr[r-1][i]<=0)
				arr[r-1][i]=1;
		}
		for(i=r-2;i>=0;i--)
		{
			arr[i][c-1]=arr[i+1][c-1]-arr[i][c-1];
			if(arr[i][c-1]<=0)
				arr[i][c-1]=1;
		}
		for(i=r-2;i>=0;i--)
		{
			for(j=c-2;j>=0;j--)
			{
				arr[i][j]=min(arr[i][j+1],arr[i+1][j])-arr[i][j];
				if(arr[i][j]<=0)
					arr[i][j]=1;
			}
		}
		cout<<arr[0][0]<<"\n";
	}
	return 0;
}
