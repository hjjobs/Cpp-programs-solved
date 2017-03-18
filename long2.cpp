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
		ll r,g,b,k,sum=0;
		cin>>r>>g>>b;
		cin>>k;
		r=r-k+1;g=g-k+1;b=b-k+1;
		sum=sum+3*(k-1);
		if(r<0)
			sum+=r;
		if(g<0)
			sum+=g;
		if(b<0)
			sum+=b;
		cout<<sum+1<<"\n";
	}
	return 0;
}
