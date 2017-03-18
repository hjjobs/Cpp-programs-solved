#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pch pair<int,int>
#define m_p make_pair(n,m)
#define pb push_back
#define bp(x) __builtin_popcount(x)
#define pi 3.14159265
typedef long long int ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int dp[27][729][27];
int arr[27]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
void solve()
{
    int i,ch,j,k;
    for(i=1;i<=26;i++)
        dp[1][i][i]=1;
    for(ch=2;ch<=26;ch++)
    {
        for(i=1;i<=26*26;i++)
        {
            for(j=1;j<=26;j++)
            {
                for(k=1;k<arr[j];k++)
                {
                    if((i-arr[j])>0)
                        dp[ch][i][arr[j]]+=dp[ch-1][i-arr[j]][k];
                }
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    solve();
    while(t--)
    {
        int l,p;
        cin>>l>>p;
        ll ans=0;
        if(l>26)
        {   
            cout<<0<<"\n";
        }
        else
        {
            for(int i=1;i<=26;i++)
            {
                ans=ans+dp[l][p][i];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}