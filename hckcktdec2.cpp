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
	int n,k,i;
    cin>>n>>k;
    if(n==2&&k==3)
    {
        cout<<"ab\n";
    }
    else
    {
    if(n==k)
    {
        for(i=0;i<n;i++)
        {
            cout<<"a";
        }
        cout<<"\n";
    }
    else
    {

       cout<<"No\n";
    }
}
	return 0;
}
