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
		int i,j,n,rk,sv;
		ll sum=0;
		string s1,s;
		cin>>n;
		cin>>s;
		if(s=="INDIAN")
		{
			for(i=0;i<n;i++)
			{
				cin>>s1;
				if(s1=="CONTEST_WON")
				{
					cin>>rk;
					sum+=300;
					if(rk<20)
						sum+=(20-rk);
				}
				else if(s1=="TOP_CONTRIBUTOR")
				{
					sum+=300;
				}
				else if(s1=="BUG_FOUND")
				{
					cin>>sv;
					sum+=sv;
				}
				else if(s1=="CONTEST_HOSTED")
				{
					sum+=50;
				}
			}
			cout<<(sum/200)<<"\n";
		}
		else
		{
			for(i=0;i<n;i++)
			{
				cin>>s1;
				if(s1=="CONTEST_WON")
				{
					cin>>rk;
					sum+=300;
					if(rk<20)
						sum+=(20-rk);
				}
				else if(s1=="TOP_CONTRIBUTOR")
				{
					sum+=300;
				}
				else if(s1=="BUG_FOUND")
				{
					cin>>sv;
					sum+=sv;
				}
				else if(s1=="CONTEST_HOSTED")
				{
					sum+=50;
				}
			}
			cout<<(sum/400)<<"\n";
		}
	}
	return 0;
}
