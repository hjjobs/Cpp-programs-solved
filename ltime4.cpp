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
ll arr[35005];
bool visited[35005];
ll i;
vector <ll> adj[35005];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
void initialize() 
{
    for(ll i=0;i<35005;i++)
     	visited[i] = false;
}
bool dfsF(ll s,ll *mini,ll *maxi,ll tar) 
{
	
    visited[s] = true;
    if(s==tar)
		return true;
    for(ll i=0;i<adj[s].size();i++)    
    {
	     if(visited[adj[s][i]]==false)
  		{
  			if(dfsF(adj[s][i],mini,maxi,tar))
  			{
  				*mini=min(*mini,arr[adj[s][i]]);
  				*maxi=min(*maxi,arr[adj[s][i]]);
  				return true;
  			}
  		}
    }
    return false;
}
vector <ll > v;
bool dfsC(ll s,ll tar) 
{
	
    visited[s] = true;
    if(s==tar)
		return true;
    for(ll i=0;i<adj[s].size();i++)    
    {
	     if(visited[adj[s][i]]==false)
  		{
  			if(dfsC(adj[s][i],tar))
  			{
  				v.push_back(arr[adj[s][i]]);	
  				return true;
  			}
  		}
    }
    return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll x,y;
    for(i=0;i<n-1;i++) 
    {
	     cin>>x>>y;
	     x--;y--;     
	     adj[x].push_back(y);                  
	     adj[y].push_back(x);                 
    }
    ll q;
    cin>>q;
    ll z;
    for(z=0;z<q;z++)
    {
    	char a;
    	ll t1,t2;
    	cin>>a;
    	if(a=='C')
    	{
    		initialize();
    		v.clear();
    		cin>>t1>>t2;
    		t1--;t2--;
    		dfsC(t1,t2);
    		sort(v.begin(), v.end());
    		ll ans=abs(arr[t1]-arr[t2]);
    		for(i=0;i<v.size()-1;i++)
    		{
    			ll dif;
    			dif=v[i+1]-v[i];
    			ans=min(ans,dif);
    		}
    		cout<<ans<<"\n";
    	}
    	else if(a=='F')
    	{
    		initialize();
    		cin>>t1>>t2;
    		t1--;t2--;
    		ll mini=arr[t1];
    		ll maxi=arr[t1];
    		dfsF(t1,&mini,&maxi,t2);
    		cout<<maxi-mini<<"\n";
    	}
    }
	return 0;
}
