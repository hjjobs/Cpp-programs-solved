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
bool vis[1005];
 
int dfs(int src,int des,vector<int> v[],int b[],int k[],int ans)
{
    //cout<<src<<" \n";
    vis[src]=1;
    if(src==des)
    {
        return ans;
    }
    int mini=999999;
     
    for(int i=0;i<v[src].size();i++)
    {
        int te[11];
        for(int h=0;h<=10;h++)
        {
            te[h]=b[h];
        }
        if(vis[v[src][i]])continue;
        if(!te[k[v[src][i]]])
        {
            te[k[v[src][i]]]=1;
            mini=min(mini,dfs(v[src][i],des,v,te,k,ans+1));
 
        }
        else
        {
 
            mini=min(mini,dfs(v[src][i],des,v,te,k,ans));
             
        }
    }
    return mini;
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
int t,tc;
cin>>tc;
for(t=0;t<tc;t++)
{
int n,m;
cin>>n>>m;
vector<int> v[1005];
int i,x,y;
int ans=10;
for(i=0;i<m;i++)
{
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
int k[1005];
for(i=1;i<=n;i++)
{
    cin>>k[i];
}
int src,des;
cin>>src>>des;
int l=1;
int r=10;
while(l<=r)
{
    int mid=(l+r)/2;
    //cout<<mid<<"=>\n";
    int b[10]={0};
    b[k[src]]=1;
    memset(vis,0,sizeof(vis));
    int temp=dfs(src,des,v,b,k,1);
    //cout<<temp<<"\n";
    if(temp<=mid)
    {
        ans=mid;
        r=mid-1;
    }
    else
    {
        l=mid+1;
    }
}
cout<<ans<<"\n";
}
    return 0;
}