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
int arr[1000005];
int main()
{
	int n,i;
	cin>>n;
	int temp=n;
	int k;
	if(n%2==0)
	{
		k=0;
		for(i=1;i<n;i+=2)
		{
			arr[k++]=i;
		}
		for(i=n-1;i>=1;i-=2)
		{
			arr[k++]=i;
		}
	}
	else
	{
		k=0;
		for(i=1;i<=n;i+=2)
		{
			arr[k++]=i;
		}
		for(i=n-2;i>=1;i-=2)
		{
			arr[k++]=i;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
    return 0;
}