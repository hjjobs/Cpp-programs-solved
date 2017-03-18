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
	int n,q,i,j,ind;
	char ch;
	string a,temp;
	cin>>n>>q;
	cin>>a;
	for(i=0;i<q;i++)
	{
		cin>>ind>>ch;
		a[ind-1]=ch;
		char prev=a[0];
		int c=0,sum=0,t=0;
		for(j=0;j<a.length();j++)
		{
			if(a[j]=='.')
				c++;
			if(prev=='.'&&a[j]!='.')
				t++;
			prev=a[j];
		}
		if(c==a.length())
			sum=c-1;
		else
			sum=c-t+1;
		cout<<sum<<"\n";
	}
	return 0;
}
