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
int MOD=1000000007;
int n,i,j,q,r,p,f;
vector <int> fact[100005];
ll prod[100005];
long double sum[100005];
int arr[100005];
int check[100005];
ll ipow(ll a,ll b)
{
	ll x=1,y=a; 
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
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	for(i=0;i<100005;i++)
	{
		prod[i]=1;
		sum[i]=0;
		check[i]=0;
	}
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=1;i<=n;i++)
	{
	     for(j=i;j<n;j=j+i)
	     {
	     	sum[i]=sum[i]+log10(arr[j]+0.0000001);
	     	prod[i]=(prod[i]*(arr[j]));
	     	if(prod[i]>MOD)
	     	    prod[i]%=MOD;
	     }
	}
	cin>>q;
	int z;
	for(z=0;z<q;z++)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			cin>>p>>f;
			ll temp=arr[p-1];
			arr[p-1]=f;
			ll inv=ipow(temp,MOD-2);
			if((p-1)==0)
			{
				arr[0]=f;
			}
			else
			{
				if(check[p-1]==0)
    		{
				for(j=1;j<=sqrt(p-1);j++)
               {   
    	         if((p-1)%j==0)
		          {
			        fact[p-1].push_back(j);
      		          if(j*j!=(p-1))
      			      fact[p-1].push_back((p-1)/j);
		            }
                }
	            for(i=0;i<fact[p-1].size();i++)
    		    {
    		    	sum[fact[p-1][i]]-=log10(temp+0.0000001);
    		        prod[fact[p-1][i]]=(prod[fact[p-1][i]]*inv);
    		        if(prod[fact[p-1][i]]>MOD)
            		   prod[fact[p-1][i]]%=mod;
    		        sum[fact[p-1][i]]+=log10(arr[p-1]+0.0000001);
    		        prod[fact[p-1][i]]=(prod[fact[p-1][i]]*arr[p-1])%(MOD);
    		        if(prod[fact[p-1][i]]>MOD)
    		            prod[fact[p-1][i]]%=MOD;
                }
                check[p-1]=1;
    		}
    	    else if(check[p-1]==1)
    	    {
    	               for(i=0;i<fact[p-1].size();i++)
            		   {
            		    	sum[fact[p-1][i]]-=log10(temp+0.0000001);
            		        prod[fact[p-1][i]]=(prod[fact[p-1][i]]*inv);
            		        if(prod[fact[p-1][i]]>MOD)
            		            prod[fact[p-1][i]]%=mod;
            		        sum[fact[p-1][i]]+=log10(arr[p-1]+0.0000001);
            		        prod[fact[p-1][i]]=(prod[fact[p-1][i]]*arr[p-1])%(MOD);
            		        if(prod[fact[p-1][i]]>MOD)
            		            prod[fact[p-1][i]]%=MOD;
                       }	
    	    }
			}
		}
		else
		{
			long double logs=(long double)0;
			long double logs1=(long double)0;
			int re;
			cin>>r;
			logs1=log10(arr[0]+0.0000001);
			logs=(sum[r]+logs1)-floor(sum[r]+logs1);
			re=floor(pow(10,logs));
			ll value=(arr[0]*prod[r])%MOD;
			cout<<re;
			cout<<" "<<value<<"\n";
		}
	}
	return 0;
}