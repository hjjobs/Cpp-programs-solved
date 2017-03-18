#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair
#define mod 1000000007
#define pb push_back
#define bp(x) __builtin_popcount(x)
#define PI acos(-1)
typedef long long int ll;
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

bool vis[1000005];
pair <int,int> p[1000005];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  map < pair<int,int> , int > mm;
  vector < pair< pair<int,int> , int > > out;
  vector < pair<int,int> > v[100005];
  queue < pair<int,int> > q;
  int n,m,x,y,i;
  int c=0;
  scanf("%d %d",&n,&m);
  for(i=1;i<=m;i++)
  {

      scanf("%d %d",&x,&y);
      v[x].pb(m_p(y,i));
      v[y].pb(m_p(x,i));
      mm[m_p(x,y)]++;
      mm[m_p(y,x)]++;
      p[i].first=x;
      p[i].second=y;
    }
    int j,id;
    int e,f,g,h;
    for(i=1;i<=m;i++)
    {
        x=p[i].first;
        y=p[i].second;
        if(!vis[i]&&mm[m_p(x,y)]>0)
        {
            while (!q.empty())
            {
                q.pop();
            }
         for(j=0;j<v[y].size();j++)
         {
                e=v[y][j].first;
                f=v[y][j].second;
               if(mm[m_p(y,e)]>0&&vis[f]==0)
               {
                   q.push(v[y][j]);
               }
         }
         int flag=0,we;
         while(!q.empty()&&flag==0)
         {
             pair<int,int> temp;
             temp=q.front();
              e=temp.first;
              we=temp.second;
                 for(int u=0;u<v[x].size();u++)
                 {
                     int node=v[x][u].first;
                      id=v[x][u].second;
                     if(node==e&&vis[id]==0&&mm[m_p(x,e)]>0)
                     {
                         flag=1;
                         c++;
                         break;
                     }
                 }
                 if(flag==1)
                 {
                 	 mm[m_p(x,e)]--;
                   mm[m_p(e,x)]--;
                   mm[m_p(y,x)]--;
                   mm[m_p(x,y)]--;
                   mm[m_p(e,y)]--;
                   mm[m_p(y,e)]--;
                  out.push_back(m_p(m_p(we,id),i));
                   vis[i]=1;
                   vis[we]=1;
                   vis[id]=1;
                 }
                 q.pop();
               }
         }
       }
    printf("%d\n",c);
    for(i=0;i<out.size();i++)
    {
      printf("%d %d %d\n",out[i].second,out[i].first.first,out[i].first.second);
    }
	return 0;
}