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
		string a;
		int i;
		cin>>a;
		int len=a.length();
		int idx=0;
		if(a[(len/2)]=='.')
		{
			a[(len/2)]=='a';
		}
		for(i=0;i<len;i++)
		{
			idx=i;
			if(a[i]=='.'&&a[len-1-idx]!='.')
			{
				a[idx]=a[len-1-idx];
			}
			else if(a[i]=='.'&&a[len-1-idx]=='.')
			{
				a[i]='a';
				a[len-1-idx]='a';
			}
		}
		int flag=0;
		for(i=0;i<len;i++)
		{
			if(a[i]!=a[len-1-i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<a<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
	return 0;
}
