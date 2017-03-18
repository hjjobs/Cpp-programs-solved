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
	ios::sync_with_stdio(false);cin.tie(0);
	int r,c,i,j;
	int a[1003][1003];
	int temp1[1003]={0};
	int temp2[1003]={0};
	memset(a,0,sizeof(a));
	cin>>r>>c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	int q,l,r;
	cin>>q;
	for(i=0;i<q;i++)
	{
		int val1,val2,val3;
		cin>>l>>r;
		for(j=0;j<r;j++)
		{
			val1=lower_bound(a[j],a[j]+c,l)-a[j];
			val2=upper_bound(a[j],a[j]+c,r)-a[j];
			temp1[j]=val1;
			temp2[j]=val2;
		}
		cout<<val3;
	}
	return 0;
}