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
bool isprime[1000005];
int ans[1000005];
std::vector<int> v;
void sieve()
{
	for(int i=0;i<1000001;i++)
		isprime[i]=1;
	for(int i=2;i<=sqrt(1000001);i++)
	{
		if(isprime[i]==1)
		{
			for(int j=i*i;j<1000001;j=j+i)
			{
				isprime[j]=0;
			}
		}
	}
}
void primeFactors(int n)
{
    while (n%2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
           v.push_back(i);
           n = n/i;
        }
    }
    if (n > 2)
        v.push_back(n);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	sieve();
	int t;
	cin>>t;
	ans[2]=1;
	for(int i=3;i<=1000001;i++)
	{
		if(isprime[i]==1)
		{
			ans[i]=ans[i-1]+1;
		}
		else
		{
			primeFactors(i);
			ans[i]=ans[i-1]+v.size();
			v.clear();
		}
	}
	while(t--)
	{
		int n;
		cin>>n;
		cout<<ans[n]<<"\n";
	}
	return 0;
}
