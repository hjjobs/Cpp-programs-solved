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
	int t,i,j;
	cin>>t;
	while(t--)
	{
		string a;
		int c0=0;
		int c1=0;
		int count=0;
		cin>>a;
		int len=a.length();
		if(a[0]=='1')
		{
			c1++;
			count++;
		}
		for(i=0;i<len-1;i++)
		{
			if(a[i]=='1'&&a[i+1]=='1')
			{
				c1++;

			}
			if(c1==len&&c1%2==0)
			{
				count=c1/2;
			}
			else if(c1==len&&c1%!=0)
			{
				count=(c1/2)+1;
			}
			if(a[i]!=a[i+1])
			{
				if(c1%2==0&&c1>0)
				{
					count=count+c1/2;
				}
				else if(c1%2!=0&&c1>0)
				{
					count=count+1+c1/2;
				}
				if(c0%2==0&&c0>0)
				{
					count=count+c0/2;
				}
				else if(c0%2!=0&&c0>0)
				{
					count=count+1+c0/2;
				}
				c1=0;
				c0=0;
				count++;
			}
			if(a[i]=='0'&&a[i+1]=='0')
			{
				count++;
				c0+=2;
			}


		}
	}
	return 0;
}