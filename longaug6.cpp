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
int cnt;
ll arr[100]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733};
ll x,n,i;
ll func(ll c,ll total, ll idx)
{
    
	ll target=x;
    ll sum = 0, i;
    if (c > target || total < 0)
            return 0;
    if (target == c && total == 0)
            return 1;
    if (target == c && total < 0)
            return 0;
    if (target == c && total > 0)
        return 0;
    if(c+arr[idx]*total==x)
    	return 1;
    if(c+arr[idx]*total<x)
    	return 0;
	for (i=idx;i>=0;i--) 
    {
        sum=sum+func(c+arr[i], total-1, i);
    }
    return sum;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cnt=43;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x>>n;
		cout<<func(0,n,42)<<"\n";
	}
	return 0;
}