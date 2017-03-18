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
vector<string> v[55][55];

void generate_strings(string prefix,int len, int numBits,int y,int n)
{
    
    if (y== numBits&&len==n)
         v[n][numBits].push_back(prefix);
    else if(len<n)
    {
	    generate_strings(prefix + "0", len+1, numBits,y,n);
	    generate_strings(prefix + "1", len+1, numBits+1,y,n);
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	int i,j;
	for(i=1;i<=50;i++)
	{
		for(j=0;j<=i;j++)
		{
          generate_strings("",0,0,j,i);
		}
	}
	while(t--)
	{
		int n;
		int k;
		int w[55];
		int x[550];
		int c[550];
		cin>>n;
		for(i=0;i<n;i++)
			cin>>w[i];
		cin>>k;
		for(i=0;i<k;i++)
			cin>>x[i];
		for(i=0;i<k;i++)
			cin>>c[i];
		for(i=0;i<k;i++)
		{
			generate_strings("",0,0,x[i],n);
		}
		int l;
		for(i=0;i<k;i++)
		{
			int flag=0;
			for(j=0;j<v[n][x[i]].size()&&flag==0;j++)
			{
				string s=v[n][x[i]][j];
				ll sum=0;
				for(l=0;l<n;l++)
				{
					if(s[l]=='1')
						sum=sum+w[i];
				}
				if(sum==c[i])
				{
					flag=1;
				}
			}
		   if(flag==0)
		   	cout<<"No"<<"\n";
		   else
		   	cout<<"Yes"<<"\n";
		}

	}
	return 0;
}
