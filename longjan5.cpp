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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q,i,j,p;
        cin>>n>>q>>p;
        int arr[10005]={0};
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<q;i++)
        {
            int ch;
            cin>>ch;
            if(ch==1)
            {
                int x,y;
                cin>>x>>y;
                arr[x]=y;
            }
            else
            {
                int l,r;
                cin>>l>>r;
                
            }
        }

    }
    return 0;
}