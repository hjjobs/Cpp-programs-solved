#include <bits/stdc++.h>
 
using namespace std;
 
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define MOD 1000000007
typedef long long int ll;
long long int ipow(int a, int b)
{
	long long x=1,y=a; 
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD; 
		b /= 2;
	}
	return x;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		int n,x;
		ll m;
		ll a[100001]={0};
		scanf("%d",&n);
		scanf("%d",&x);
		scanf("%lld",&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll fact[100001];
		ll arr[100001];
		fact[0]=1;
		arr[0]=1;
    	int i=1;
		ll temp=MOD-2;
		while(i<=100001)
	    {
	        fact[i]=(fact[i-1]*i)%MOD;
	        arr[i]=(arr[i-1]*(m+i-1))%MOD;
	        i++;
	    }
	    i=1;
	    while(i<=100001)
	    {
	        fact[i]=(arr[i]%MOD*(ipow(fact[i],temp)%MOD))%MOD;
	        cout<<fact[i]<<" ";
	        i++;
	    }
	    ll sum=0;
		for(int j=1;j<x;j++)
		{
			sum=sum+(fact[j]*a[x-j]);
			//cout<<fact[j]<<" ";

		}
		sum=sum+a[x];
		printf("%lld\n",sum);
	}
	return 0;
}