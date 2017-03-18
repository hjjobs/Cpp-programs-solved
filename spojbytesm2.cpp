#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
typedef long long int ll;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int r,i,j,c;
		cin>>r>>c;
		int a[r+4][c+4];
		for(i=0;i<=c+1;i++)
		{
			a[0][i]=0;
		}
		for(i=0;i<=r+1;i++)
		{
			a[i][0]=0;
			a[i][c+1]=0;
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				a[i][j]+=max(a[i-1][j],max(a[i-1][j-1],a[i-1][j+1]));
			}
		}
		//cout<<a[4][1];
		int temp=0;
		for(i=1;i<=c;i++)
		{
			temp=max(temp,a[r][i]);
		}
		cout<<temp<<"\n";
	}
	return 0;
}
