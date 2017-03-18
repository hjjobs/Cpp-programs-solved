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
		int n,m,i,j;
		cin>>n>>m;
		ll arr[100005];
		ll arr1[100005];
		ll sum=0;
		for(i=0;i<n;i++)
		{
			ll tt,tt1;
			cin>>tt;
			tt1=tt;
			tt1/=2;
			tt=tt/5;
			int ct=0;
			while(tt!=0)
			{
				tt=tt/5;
				ct++;
			}
			arr[i]=ct;
			ct=0;
			while(tt1!=0)
			{
				tt1=tt1/2;
				ct++;
			}
			arr1[i]=ct;
		}
		for(i=0;i<m;i++)
		{
			int ch;
			ll l,r,x,y;
			cin>>ch;
			if(ch==1)
			{
				cin>>l>>r>>x;
				l--;r--;
				ll tt1=x;
				tt1=tt1/5;
				int ct1=0; 
				while(tt1!=0)
				{
					tt1=tt1/5;
					ct1++;
				}
				tt1=x;
				tt1=tt1/2;
				int ct2=0; 
				while(tt1!=0)
				{
					tt1=tt1/2;
					ct2++;
				}
				for(j=l;j<=r;j++)
				{
					arr[j]=arr[j]+ct1;
					arr1[j]=arr1[j]+ct2;
				}
			}
			else if(ch==2)
			{
				cin>>l>>r>>y;
				l--;r--;
				for(j=l;j<=r;j++)
				{
					ll tt2=(j-l+1)*y;
					ll tt3=(j-l+1)*y;
					tt2/=5;
					tt3/=2;
					int ct2=0;
					while(tt2!=0)
					{
						tt2=tt2/5;
						ct2++;
					}
					arr[j]=ct2;
					int ct3=0;
					while(tt3!=0)
					{
						tt3/=2;
						ct3++;
					}
					arr1[j]=ct3;
				}
			}
			else
			{
				cin>>l>>r;
				l--;r--;
				int cnt1=0;
				int cnt2=0;
				for(j=l;j<=r;j++)
				{
					cnt1+=(arr[j]);
					cnt2+=arr1[j];
				}
				sum+=min(cnt1,cnt2);//cout<<cnt<<"\n";
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
