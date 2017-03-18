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
		string a,b;
		int h1[30]={0};
		int h2[30]={0};
		int h3[30]={0};
		int i;
		cin>>a>>b;
		int len1=a.length();
		for(i=0;i<len1;i++)
		{
			h1[a[i]-'a'+1]++;
			h2[b[i]-'a'+1]++;
		}
		int flag=0;
		int c1=0,c2=0;
		for(i=0;i<len1;i++)
		{
			if(b[i]=='.')
			{
				c1++;
			}
		}
		for(i=1;i<=26;i++)
		{
			if(h1[i]>=h2[i])
			{
				c2=c2+abs(h1[i]-h2[i]);
				h3[i]=abs(h1[i]-h2[i]);
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(c1!=c2)
		{
			flag=1;
		}
		if(flag==1)
		{
			cout<<"-1\n";
		}
		else
		{
			int j=1;
			for(i=0;i<len1;i++)
			{
				if(b[i]=='.')
				{
					while(h3[j]==0&&j<26)
					{
						j++;
					}
					b[i]=(char)(j+'a'-1);
					h3[j]--;
				}
			}
			cout<<b<<"\n";
		}
	}
	return 0;
}
