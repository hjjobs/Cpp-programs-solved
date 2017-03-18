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
		int i,c=0,r=0,t10=0,t01=0;
		string a,b;
		cin>>a>>b;
		for(i=0;i<a.length();i++)
		{
			if(a[i]=='0')
				c++;
			if(a[i]=='1')
				r++;
		}
		if(c==a.length()||r==a.length())
		{
			cout<<"Unlucky Chef\n";
		}
		else
		{
			for(i=0;i<a.length();i++)
			{
				if(a[i]=='1'&&b[i]=='0')
				{
					t10++;
				}
				if(a[i]=='0'&&b[i]=='1')
				{
					t01++;
				}
			}
			if(t10>=t01)
			{
				cout<<"Lucky Chef\n";
				cout<<t10<<"\n";
			}
			else
			{
				cout<<"Lucky Chef\n";
				cout<<t01<<"\n";
			}
		}
	}
	return 0;
}
