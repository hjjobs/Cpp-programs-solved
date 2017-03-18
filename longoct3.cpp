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
	int t;
	cin>>t;
	while(t--)
	{
		string l1,l2,l3;
		int n,i,j;
		cin>>l1>>l2>>l3;
		string temp=l2;
		bool flag=false;
		cin>>n;
		int len1=l1.length();
		int len2=l2.length();
		int len3=l3.length();
		int carry=1;
		for(i=len3-1;i>=0;i--)
		{
			if(l3[i]=='1'&&carry==0)
			{
				l3[i]='1';
				carry=0;
			}
			else if(l3[i]=='0'&&carry==1)
			{
				l3[i]='1';
				carry=0;
			}
			else if(l3[i]=='1'&&carry==1)
			{
				l3[i]='0';
				carry=1;
			}
		}
		for(i=len2-1;i>=0;i--)
		{
			if(l2[i]=='1'&&carry==0)
			{
				l2[i]='1';
				carry=0;
			}
			else if(l2[i]=='0'&&carry==1)
			{
				l2[i]='1';
				carry=0;
			}
			else if(l2[i]=='1'&&carry==1)
			{
				l2[i]='0';
				carry=1;
			}
		}
		if(carry==1)
		{
			flag=true;
		}
		for(i=len1-1;i>=0;i--)
		{
			if(l1[i]=='1'&&carry==0)
			{
				l1[i]='1';
				carry=0;
			}
			else if(l1[i]=='0'&&carry==1)
			{
				l1[i]='1';
				carry=0;
			}
			else if(l1[i]=='1'&&carry==1)
			{
				l1[i]='0';
				carry=1;
			}
		}
		ll ans=0;
		if(carry==1)
		{
			ans=1;
		}
		else
		{
			for(i=0;i<len2;i++)
			{
				if(l2[i]=='1')
					ans++;
			}
			if(flag==true)
			{
				ans=ans*n;
			}
			else
			{
				ll ans1=0;
				for(i=0;i<len2;i++)
				{
					if(temp[i]=='1')
						ans1++;
				}
				ans=ans+ans1*(n-1);
			}
			for(i=0;i<len1;i++)
			{
				if(l1[i]=='1')
					ans++;
			}
			for(i=0;i<len3;i++)
			{
				if(l3[i]=='1')
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
