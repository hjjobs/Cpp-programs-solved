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
#define PI acos(-1)
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
  ios::sync_with_stdio(false);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    ll arr[100005];
    ll sum=0;
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sum=sum/n;
    sort(arr,arr+n);
    ll ans=LLONG_MAX;
    ll mini=arr[0];
    ll maxi=arr[n-1];
    ll c=0;
    for(i=mini;i<=sum;i++)
    {
        ll temp=i;
        c=0;
        for(j=0;j<n;j++)
        {
          if(temp>arr[j])
          {
             c=c+abs(temp-arr[j]);
          }
          else if(temp<arr[j])
          {
              int k=arr[j];
              while(k>temp)
              {
                  k=k/2;
                  c++;
              }
              c=c+abs(temp-k);
          }
        }
        ans=min(ans,c);
        //cout<<c<<" "<<temp<<" ";
        //cout<<endl;
    }
    cout<<ans<<"\n";
}
	return 0;
}