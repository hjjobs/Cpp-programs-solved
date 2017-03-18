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
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m,i,j;
	cin>>n>>m;
	int b[20];
	int p[20];
	int a1[20];
	int a2[20];
	int b1[20];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		b1[i]=b[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>p[i];
	}
	int str1[20],str2[20],p1=0,p2=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<p[i];j++)
		{
			if(i%2==0)
			{
				str1[p1++]=0;
				str2[p2++]=1;
			}
			else
			{
				str1[p1++]=1;
				str2[p2++]=0;
			}
		}
	}
	/*for(i=0;i<n;i++)
	{
		cout<<str1[i]<<" ";
	}
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<str2[i]<<" ";
	}
	cout<<"\n";*/
	bool flag2=0;
	int sum=0;
	for(i=0;i<n;i++)
	{

		if(b[i]!=str2[i])
		{
			//cout<<b[i]<<" "<<i<<"***\n";
			int point=i;
			bool flag=false;
			while(b[point]!=str2[i])
			{
				
				point++;
				if(point>=n)
				{
					flag=1;
					break;
				}
			}
			//cout<<i<<" "<<point<<"\n";
			if(!flag)
			{
				int tt=b[point];
				b[point]=b[i];
				b[i]=tt;
				sum=sum+(point-i);
			}
			else
			{
				flag2=1;
				break;
			}
		}
	}
		//cout<<sum<<" "<<flag2<<"f\n";
//cout<<"********************\n";
	int sum2=0;
	bool flag3=0;
	for(i=0;i<n;i++)
	{

		if(b1[i]!=str1[i])
		{
			//cout<<b1[i]<<" "<<i<<"***\n";
			int point=i;
			bool flag=false;
			while(b1[point]!=str1[i])
			{
				//cout<<point<<" "<<b1[point]<<"lol\n";
				point++;
				if(point>=n)
				{
					flag=1;
					break;
				}
			}
			//cout<<i<<" "<<point<<"\n";
			if(!flag)
			{
				int tt=b1[point];
				b1[point]=b1[i];
				b1[i]=tt;
				sum2=sum2+(point-i);
			}
			else
			{
				flag3=1;
				break;
			}
		}
	}
	//cout<<sum2<<" "<<flag3<<"f\n";
	if(!flag2 && !flag3)
	{
		cout<<min(sum,sum2)<<"\n";
	}
	else if(!flag2)
	{
		cout<<sum<<"\n";
	}
	else
	{
		cout<<sum2<<"\n";
	}
	return 0;
}
