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
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int temp=n%8;
        if(temp==1)
        {
            cout<<n+3<<"LB\n";
        }
        else if(temp==2)
        {
            cout<<n+3<<"MB\n";
        }
        else if(temp==3)
        {
            cout<<n+3<<"UB\n";
        }
        else if(temp==4)
        {
            cout<<n-3<<"LB\n";
        }
        else if(temp==5)
        {
            cout<<n-3<<"MB\n";
        }
        else if(temp==6)
        {
            cout<<n-3<<"UB\n";
        }
        else if(temp==7)
        {
            cout<<n+1<<"SU\n";
        }
        else if(temp==0)
        {
            cout<<n-1<<"SL\n";
        }
    }
	return 0;
}
