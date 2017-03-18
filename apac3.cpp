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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
string s;
ll len;
ll h[55]={0};
ll k[55]={0};
ll cnt;
ll f(ll x)
{
   ll l=0,r=x-1,c=0,i;
    while(r<len)
    {
        int k[55]={0};
       for(i=l;i<=r;i++)
       {
          k[s[i]-'A'+1]=1;
       }
       for(i=1;i<=52;i++)
       {
           if(h[i]==k[i])
           {
               c++;
           }
       }
       if(c==cnt)
        	return 1;
        l++;
        r++;
    }

    return 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
 ios_base::sync_with_stdio(false);cin.tie(NULL);
ll n;
cin>>n;
 cin>>s;
 ll i;
 len=s.length();
 for(i=0;i<s.length();i++)
 {
   h[s[i]-'A'+1]=1;
 }
 for(i=1;i<=52;i++)
 {
   if(h[i]==1)
        cnt++;
 }
 ll low=0,high=len-1,mid,ans;
 while(low<=high)
 {
     mid=low+(high-low)/2;
     if(f(mid)==1)
     {

         ans=mid;
         high=mid-1;

     }
     else if(f(mid)==0)
    {
     low=mid+1;
    }
 }
 cout<<ans;
	return 0;
}