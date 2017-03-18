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
int n,k,i;
vector<string> v;
string s,a;
pair<int,string> p[105];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
	    cin>>s;
	    v.push_back(s);
	    p[i].first=s.length();
	    p[i].second=s;
	}
	sort(p,p+n);
	cin>>a;
	int x,y;
	for(i=0;i<n;i++)
	{
	    if(p[i].first==a.length())
	    {
	        x=i;
	        break;
	    }
	}
	y=x;
	for(i=x+1;i<n;i++)
	{
	    if(p[i].first==a.length())
	    {
	        y=i;
	    }
	    else if(v[i].length()>a.length())
	    {
	        break;
	    }
	}
	x++;
	y++;
	int mini=((x-1)/k)*5+x;
	int maxi=((y-1)/k)*5+y;
	cout<<mini<<" "<<maxi<<"\n";
    return 0;
}