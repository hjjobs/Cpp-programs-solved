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
std::vector<int> v;
void sieve()
{
	isprime[0]=0;
	isprime[1]=0;
	for(int i=2;i<=1000;i++)
	{
		if(isprime[i]==1)
		{
			for(int j=i*i;j<=1000000;j=j+i)
			{
				isprime[j]=0;
			}
		}
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	for(int i=0;i<1000001;i++)
		isprime[i]=1;
	sieve();
	for(int i=2;i<=1000000;i++)
	{
		if(isprime[i]==1)
		{
			v.push_back(i);
		}
	}
	int t,i,j;
	cin>>t;
	while(t--)
	{
		int n,i;
		cin>>n;
		int temp=upper_bound(v.begin(),v.end(),n)-v.begin();
		if(v[temp]>n)
			temp--;
		for(i=0;i<=temp;i++)
		{
			while (n%v[i] == 0)
		    {
		        printf("%d ", v[i]);
		        n = n/v[i];
		    }
		}
		cout<<"\n";
	}
	return 0;
}
