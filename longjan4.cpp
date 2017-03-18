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
        ll dp[310][310];
        ll power[11]={0};
        memset(dp,0,sizeof(dp));
        int n,i,j,k;
        cin>>n;
        string s;
        cin>>s;
        int m,x,y;
        cin>>m>>x>>y;
        power[0]=1;
        for(i=1;i<=10;i++)
        {
            power[i]=power[i-1]*10;
        }
        ll s1=0;
        for(i=1;i<=m;i++)
        {
            s1=s1*10+(s[i-1]-'0');
            dp[i][0]=s1;
            //cout<<dp[i][0]<<"\n";
        }
        dp[0][0]=1;
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=i-1;j++)
            {
                ll num=0;
                int cnt=0;
                for(k=i;k>=max(1,i-m);k--)
                {
                    //cout<<k<<"\n";
                    num=(s[k-1]-'0')*power[cnt]+num;
                    ll temp;
                    if(num==0||dp[k-1][j-1]==0)
                        temp=0;
                    else
                        temp=gcd(num,dp[k-1][j-1]);
                    if(temp>dp[i][j])
                        dp[i][j]=temp;
                    //cout<<num<<"\n";
                    cnt++;
                }
                //cout<<"\n";
            }
        }
        ll ans=0;
        for(i=x;i<=y;i++)
        {
            if(ans<dp[n][i])
                ans=dp[n][i];
            //ans=max(ans,dp[n][i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}