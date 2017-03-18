#include<bits/stdc++.h>
 
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,n) for(int i=1;i<=n;i++)
#define loops(i,m,n) for(int i=m;i<=n;i++)
#define mloop(it,m) for(map<int,int> ::iterator it=m.begin();it!=m.end();++it)
#define ll long long int
#define ini(n,v) memset(n,v,sizeof(n))
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pid pair<int,double>
#define pii pair<int,int>
#define p_q priority_queue
#define MOD 1000000007
using namespace std;
 
int main()
{
 	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    //ios::sync_with_stdio(false);cin.tie(0);cin.cout(0);
    int t;
    cin>>t;
 
    while(t--)
    {
        ll l,n;
        cin>>l>>n;
        ll arr[n];
        ll dp[n][2];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
 
        }
        for(int i=0;i<n;i++)
        {
            dp[i][0]=abs(arr[i]-1);
            dp[i][1]=abs(arr[i]-l);
        }
        ll y[n][2];
		for(int i=0;i<n;i++)
        {
            y[i][0]=min(dp[i][0],dp[i][1]);
            y[i][1]=max(dp[i][0],dp[i][1]);
        }
        ll mini=0,maxi=0;
        for(int i=0;i<n;i++)
        {
             if(mini<y[i][0])
                mini=y[i][0];
        }
        for(int i=0;i<n;i++)
        {
          	ll ans=0;
            ans=ans+(y[i][1]);
          	if(ans>maxi)
            	maxi=ans;
        }
        cout<<mini<<" "<<maxi<<"\n";
    }
    return 0;
}