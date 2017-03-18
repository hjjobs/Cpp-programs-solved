#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
#define pb push_back
#define vv vector
#define bp(x) __builtin_popcount(x)
typedef long long int ll;

ll n;
vv < string > v;
string temp1,temp2;
bool isvalid(string a)
{
  ll i,j,k;
   ll len=a.length();
  for(i=0;i<len;i++)
    for(j=i+1;j<len;j++)
      for(k=j+1;k<len;k++)
        if(a[i]==a[j]&&a[j]==a[k]&&(j-i)==(k-j))
          return 0;
      return 1;
}
void generate_strings(ll i,ll n,ll a)
{
  if(i>=n)
    {
       temp2[i]='\0';
       temp1="";
     for(ll kk=0;kk<n;kk++)
      temp1+=temp2[kk];
     if(isvalid(temp1))
       v.pb(temp1);
     return ;
 
    }
 
  for(ll de=0;de<a;++de)
  {
    
    temp2[i]=(char)('a'+de);
    generate_strings(i+1,n,a);
  }
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  ios::sync_with_stdio(false);cin.tie(0);
  int t,i,j;
  cin>>t;
  while(t--)
  {
    string s;
    ll a,k;
    cin>>a>>k;
    cin>>s;
    ll sum,hammdist;
    if(a==1)
    {
      sum=0;
      for(i=0;i<s.length();i++)
      {
        if(s[i]!='a')
        {
          sum++;  
        }
      }
      if(sum<=k&&s.length()<3)
        cout<<1<<"\n";
      else
        cout<<0<<"\n";
    }
    else if(a==2)
    {
        sum=0;
        v.clear();
        if(s.length()>8)
          cout<<"0\n";
        else 
        {
          generate_strings(0,s.length(),2);
          for(i=0;i<v.size();i++)
          {
              hammdist=0;
              for(j=0;j<s.length();j++)
                if(v[i][j]!=s[j])
                  hammdist++;
              if(hammdist<=k)
                  sum++;
          }
          cout<<sum<<"\n";
        }
    }
    else if(a==3&&s.length()<=12)
    {
      sum=0;
        v.clear();
        generate_strings(0,s.length(),3);
          for(i=0;i<v.size();i++)
          {
              hammdist=0;
              for(j=0;j<s.length();j++)
                if(v[i][j]!=s[j])
                  hammdist++;
              if(hammdist<=k)
                  sum++;
          }
          cout<<sum<<"\n";
    }
  }
return 0;
 }

 
