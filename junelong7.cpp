//https://stackoverflow.com/questions/37627085/find-the-maximum-element-in-a-matrix
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
int arr[1005][1005];
int arr1[1005][1005];
int M[11][11][1005][1005];
int i,j,x,y;
void sparsematrix(int n,int m)
{
	for(i=0;(1<<i)<=n;i++)
	{
		for(j=0;(1<<j)<=m;j++)
		{
			for(x=0;x+(1<<i)-1<n;x++)
			{
				for(y=0;y+(1<<j)-1<m;y++)
				{
					if(i==0&&j==0)
					{
                        M[i][j][x][y]=arr[x][y];
					}
                    else if(i==0)
                    {	
                    	M[i][j][x][y]=max(M[i][j-1][x][y],M[i][j-1][x][y+(1<<(j-1))]);
                    }
                    else if(j==0)
                    {
                        M[i][j][x][y]=max(M[i-1][j][x][y],M[i-1][j][x+(1<<(i-1))][y]);
                    }
                    else
                    {
                    	M[i][j][x][y]=max(M[i-1][j-1][x][y],max(M[i-1][j-1][x+(1<<(i-1))][y],max(M[i-1][j-1][x][y+(1<<(j-1))],M[i-1][j-1][x+(1<<(i-1))][y+(1<<(j-1))])));
                    }
				}
			}
		}
	}
}
int RMQ(int x,int y,int x1,int y1)
{
	int k,l;
	int ans;
    k = (int)31-__builtin_clz(x1-x+1);
    l = (int)31-__builtin_clz(y1-y+1);
    ans=max(M[k][l][x][y],max(M[k][l][x1-(1<<k)+1][y],max(M[k][l][x][y1-(1<<l)+1],M[k][l][x1-(1<<k)+1][y1-(1<<l)+1])));
    return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m,q,z;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	sparsematrix(n,m);
	arr1[1][1]=arr[0][0];
	for(i=2;i<=m;i++)
	{
		arr1[1][i]=arr1[1][i-1]+arr[0][i-1];
	}
	for(i=2;i<=n;i++)
	{
		arr1[i][1]=arr1[i-1][1]+arr[i-1][0];
	}
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=m;j++)
		{
			arr1[i][j]=arr[i-1][j-1]+arr1[i-1][j]+arr1[i][j-1]-arr1[i-1][j-1];
		}
	}
	//cout<<RMQ(0,2,2,3);
	cin>>q;
	for(int z=0;z<q;z++)
	{
		int maxi,a,b;
		int ans=INT_MAX;
		ll sum=0;
		cin>>a>>b;
		if(a==1&&b==1)
		{
			cout<<0<<"\n";
		}
		else
		{
			for(i=0;i<(n-a+1);i++)
			{
				for(j=0;j<(m-b+1);j++)
				{
					maxi=RMQ(i,j,i+a-1,j+b-1);
					int x1=i+1,y1=j+1;
					int x2=i+a;int y2=j+b;
					sum=arr1[x2][y2]+arr1[x1-1][y1-1]-arr1[x1-1][y2]-arr1[x2][y1-1];
					//cout<<sum<<" ";
					ans=min(ans,maxi*a*b-sum);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}