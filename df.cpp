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
int x,y,a,b,c,c1=0,c2=0;
cin>>x>>y;
a=y;
b=y;
c=min((2*y)-1,x);
c2=1;
while(a!=b||b!=c||c!=x)
{
  if(c2%3==1)
  {
     b=min(c+a-1,x);
  }
  else if(c2%3==2)
  {
     a=min(b+c-1,x);
  }
  else if(c2%3==0)
  {
       c=min(a+b-1,x);
  }
 c2++;
}
a=x;
b=x;
c=y;
c1++;
while(a!=b||b!=c||c!=y)
{
  if(c1%2==1)
  {
     b=max((a-c)+1,y);
  }
  else
  {
     a=max((b-c)+1,y);
  }
 c1++;
}
ll val=min(c1,c2);
cout<<val<<"\n";
  return 0;
}