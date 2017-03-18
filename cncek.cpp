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
		int i,j;
		string a;
		cin>>a;
		multiset < string > v;
		int len=a.length();
		for(i=0; i<len; i++)
		{
			for(j=1;j<=len-i;j++)
			{
				string w="";
				w=a.substr(i,j);
				v.insert(w);
			}
		    //printf("\n");
		}
		//sort(v.begin(), v.end());
		for(multiset<string>::iterator it=v.begin();it!=v.end();it++)
		{
			cout<<*it<<"\n";
		}
	}
	return 0;
}
