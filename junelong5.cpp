#include <bits/stdc++.h>
 
using namespace std;
 
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define pb push_back
#define bp(x) __builtin_popcount(x)
typedef long long int ll;
int MOD=1000000007;
int n=100005;
vector<long long> f(n + 1,1);
long long pow(int a, int b, int MOD)
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
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	f[1]=1;
	for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j,final,c=0;
		ll sum=0;
		int arr[100005]={0};
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]!=0)
				c++;
		}
		if((n-c)>0)
		{
			final=min(c,k);
			for(i=0;i<=final;i++)
			{
				if(c>=i)
					sum=(sum+(C(c,i,MOD))%MOD)%MOD;
				else
					sum=sum+0;
			}
			cout<<sum<<"\n";
		}
		else
		{
			if(k%2==0)
				final=k;
			else
				final=k-1;
			i=0;
			while(i<=final)
			{
				if(n>=(k-i))
					sum=(sum+(C(n,k-i,MOD))%MOD)%MOD;
				else
					sum=sum+0;
				i=i+2;
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}