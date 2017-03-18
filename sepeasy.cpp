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
	int n;
	cin>>n;
	int arr[100002];
	int vis[100005]={0};
	for(int j=1;j<=n;j++)
	{
		cin>>arr[j];
	}
	int s,e;
	cin>>s>>e;
	while(!vis[s]){
    	vis[s]=1;
    	s=arr[s];
    }
    if(vis[e]){
    	cout<<"Yes\n";
    }
    else{
    	cout<<"No\n";
    }
	return 0;
}
