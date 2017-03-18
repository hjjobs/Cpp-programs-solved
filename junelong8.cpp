//https://github.com/kartikkukreja/blog-codes/blob/master/src/Graham%20Scan%20Convex%20Hull.cpp
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
class Node
{
    public:
    
    ll x,y,count;
    Node(){count=0;}
 
    bool operator < (const Node &other) const 
     {
      if(x!=other.x)
        return x < other.x;
       return y<other.y;
      }
};
 
Node pv;
 vector < Node > node,temporary;
 ll distance1(Node a, Node b)  
{
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
 
ll counterclockwise(Node a, Node b, Node c) 
{
    ll surface = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (surface > 0)
        return -1;
    else if (surface < 0)
        return 1;
    return 0;
}
 

bool findord(Node a, Node b)  
{
    ll ordd = counterclockwise(pv, a, b);
    if (ordd == 0)
        return distance1(pv, a) < distance1(pv, b);
    return (ordd == -1);
}
 
stack<Node> findconvex(vector <Node >nodes, ll N)    
{
    stack<Node> convexpp;
 
    if (N < 3)
        return convexpp;
 
    ll leastY = 0;
    for (ll i = 1; i < N; i++)
        if (nodes[i] < nodes[leastY])
            leastY = i;
 
    Node temp = nodes[0];
    nodes[0] = nodes[leastY];
    nodes[leastY] = temp;
 
    pv = nodes[0];
    sort(nodes.begin() + 1, nodes.end(), findord);
 
    convexpp.push(nodes[0]);
    convexpp.push(nodes[1]);
    convexpp.push(nodes[2]);
 
    for (ll i = 3; i < N; i++) {
        Node top = convexpp.top();
        convexpp.pop();
        while (counterclockwise(convexpp.top(), top, nodes[i]) != -1)   
        {
            top = convexpp.top();
            convexpp.pop();
        }
        convexpp.push(top);
        convexpp.push(nodes[i]);
    }
    return convexpp;
}
 
 

 bool internalcheck(ll npol, vector < Node > node, ll x, ll y)
{
    ll i, j, c = 0;
      for (i = 0, j = npol-1; i < npol; j = i++) {
        if ((((node[i].y < y) && (y < node[j].y)) ||
             ((node[j].y < y) && (y < node[i].y))) &&
            (x < (node[j].x - node[i].x) * (y - node[i].y) / (node[j].y - node[i].y) + node[i].x))
          c = !c;
      }
      return c;
}      
 
 int main()
 {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t,i,j,k,x,y,posi,ii;
    char ch;
    cin>>t;

    ll tot_testcase=0;
    while(t--)
    {
        double ans=-1.0;
        node.clear();
        ll n;
        cin>>n;
        tot_testcase+=n;
 
        for(i=0;i<n;i++)
        {
            cin>>ch;
            cin>>x>>y;
            if(ch=='+')
            {
                 posi=-1;
              for(k=0;k<node.size();k++)
                if(node[k].x==x&&node[k].y==y)
                {
                    posi=k;
                    break;
                }
                if(posi!=-1)
                    node[posi].count++;
                else{
                    Node tt;
                    tt.x=x;
                    tt.y=y;
                    tt.count=0;
                    node.push_back(tt);
                }
 
            }
            else 
                {
                    Node temp;
                    temp.x=x;
                    temp.y=y;
                    ll posi=-1;
                    for(k=0;k<node.size();k++)
                        if(node[k].x==temp.x&&node[k].y==temp.y)
                        {
                            posi=k;
                            break;
                        }
                    if(posi!=-1)
                        {
                            node[posi].count--;
                            if(node[posi].count<=0)
                                node.erase(node.begin()+posi);
                        }
                }
                if(tot_testcase>4500&&temporary.size()>0&&ans!=-1.0&&internalcheck(temporary.size(),temporary,x,y))
                {
                    cout<<ans<<endl;continue;
                }
             stack<Node> convexpp = findconvex(node,node.size());
              if(convexpp.empty())
              {
                printf("0.0\n");continue;
              }
             
                temporary.clear();
              while(!convexpp.empty())
              {
                Node temp=convexpp.top();
                convexpp.pop();
                temporary.push_back(temp);
              }
              double surface=0.0 ;
 
  ll j=temporary.size()-1  ;
 cout<<fixed;
   cout<<setprecision(1);
 
  for (ii=0;ii<temporary.size();ii++)
  {
    surface+=(temporary[j].x+temporary[ii].x)*(temporary[j].y-temporary[ii].y);
    j=ii; 
   }
   
 ans=abs(surface)*0.5;
 cout<<ans<<endl;
        }
    }
    return 0;
 
 
 }