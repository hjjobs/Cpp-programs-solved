#include <bits/stdc++.h>
#define MAX 100100
#define mod 1000000007
#define MS0(x) memset(x, 0, sizeof(x))
#define ll long long int
#define in(x) scanf("%I64d", &x)
#define ind(x) scanf("%d", &x)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pid pair<int,double>
#define pii pair<int,int>
#define p_q priority_queue
#define gcd(a,b) __gcd(a,b)
using namespace std;
string to_string(int x)
{
    string s="";
    while(x!=0)
    {
        int d=x%10;
        s+=d+'0';
        x/=10;
    }
    reverse(s.begin(),s.end());
    return s;

}
int main()
{
  #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t,tc;
 cin>>tc;
 for(t=1;t<=tc;t++)
 {
  int n,m,x,i,j,k;
  cin>>n>>m;
  int cost[301][301]={0};
  for(i=1;i<=n;i++)
  {
    vector<int> v;
    for(j=1;j<=m;j++)
    {
      cin>>x;
      v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(j=1;j<=m;j++)
    {
      cost[i][j]=v[j-1];
    }
  }
 ll fi[305][305];
  for (i=0;i<304;i++)
 {
    for(j=0;j<304;j++)
    {
        fi[i][j]=0;
    }
 }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=j;k++)
        {
           fi[i][j]=fi[i][j]+cost[i][k];
        }
       fi[i][j]=fi[i][j]+(j*j);
    }
  }
/*for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      cout<<fi[i][j]<<" ";
    }
    cout<<"\n";
  }*/
 ll dp[305][305];
 //memset(dp,INT_MAX,sizeof(dp));
 for (i=0;i<304;i++)
 {
    for(j=0;j<304;j++)
    {
        dp[i][j]=LLONG_MAX;
    }
 }
 for(j=0;j<=m;j++)
  {
    dp[0][j]=0;
  }
  int p=0;
  dp[1][0]=0;
   for(j=1;j<=m;j++)
  {
    p++;
    dp[1][j]=dp[1][j-1]+cost[1][j]+(p*p)-((p-1)*(p-1));
  }
  for(j=0;j<=m;j++)
  {
    dp[j][0]=0;
  }

  for(i=2;i<=n;i++)
  {
    for(j=0;j<=n;j++)
    {
      for(k=0;k<=j&&k<=m;k++)
      {
        if(dp[i][j]>(fi[i][k]+dp[i-1][j-k]))
        {
            dp[i][j]=fi[i][k]+dp[i-1][j-k];
        }
      }
    }
  }
/*for(i=0;i<=n;i++)
{
    for(j=0;j<=n;j++)
    {
        cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
}*/
ll ans=dp[1][n];
for(i=1;i<=n;i++)
{
    if(ans>dp[i][n])
        ans=dp[i][n];
}
cout<<ans<<"\n";
}
  return 0;
}