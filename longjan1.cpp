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
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        ll c,d,l;
        cin>>c>>d>>l;
        ll mini=4*d+4*(max(0,c-2*d));
        ll maxi=4*(d+c);
        if(l>=mini&&l<=maxi&&l%4==0)
        {
            cout<<"yes\n";
        } 
        else
        {
            cout<<"no\n";
        }
    }
    return 0;
}