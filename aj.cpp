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
#define PI acos(-1)
typedef long long int ll;
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
int solve(int x,int y,int z){
    if(z<=x)return y-z;
    if(z>=y)return z-x;
    return min(z-x+y-x,y-z+y-x);
}
int arr[1000005];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int n,a,i;
	cin>>n>>a;
	int arr[100005];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(n==1)
	{
        cout<<0<<"\n";
        return 0;
    }
    int ans=INT_MAX;
    if(a<=arr[0])
    {
        ans=min(ans,arr[n-2]-a);
    }
    else if(a>=arr[n-1])
    {
        ans=min(ans,a-arr[1]);
    }
    else 
    {
        ans=min(ans,solve(arr[1],arr[n-1],a));
        ans=min(ans,solve(arr[0],arr[n-2],a));
    }
    cout<<ans<<"\n";
	return 0;
}
