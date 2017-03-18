#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector < string > strlist;
 
bool check(string str)
{
   int n=str.length();
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      for(int k=j+1;k<n;k++)
      {
        if(str[i]==str[j]&&str[j]==str[k]&&(j-i)==(k-j))
          return false;
      }
      return true;
}
 
 
string valid,strt;
void strmaker(int i,int n,int a)
{
  if(i>=n)
    {
       valid="";strt[i]='\0';
     for(int kk=0;kk<n;kk++)
      valid+=strt[kk];
     if(check(valid))
      {strlist.push_back(valid);
      }return ;
 
    }
 
  for(int ii=0;ii<a;ii++)
  {
    char ch=(char)('a'+ii);
    strt[i]=ch;
    strmaker(i+1,n,a);
  }
}
string error;
main()
{
  #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    int a,k;
    cin>>a>>k;
 
    cin>>error;
 
 
    if(a==1)
      {
        string e="";
        for(int i=0;i<error.length();i++)
          e+='a';
        if(!check(e))
          cout<<0<<endl;
        else
        {
          int differ=0;
          for(int i=0;i<error.length();i++)
            if(e[i]!=error[i])
              differ++;
          if(differ<=k)
            printf("1\n");
           else printf("0\n");
        }
      }
 
 
    else if(a==2)
      {
        strlist.clear();
        if(error.length()>8)
          printf("0\n");  //no good string
        else {
              strmaker(0,error.length(),2);
              int ans=0;
              for(int i=0;i<strlist.size();i++)
              {
              int differ=0;
              for(int j=0;j<error.length();j++)
                if(strlist[i][j]!=error[j])
                  differ++;
              if(differ<=k)
                  ans++;
              }
            printf("%lld\n",ans);
           }
 
      }
    else
      {
        strlist.clear();
        if(error.length()>k)
          cout<<0<<endl;
        else
        {
          strmaker(0,error.length(),3);
              int ans=0;
              for(int i=0;i<strlist.size();i++)
              {
              int differ=0;
              for(int j=0;j<error.length();j++)
                if(strlist[i][j]!=error[j])
                  differ++;
              if(differ<=k)
                  ans++;
              }
            printf("%lld\n",ans);
 
        }
      }
 
   }
return 0;
 
}