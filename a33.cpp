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
multiset < string > v;
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
 
/* A function to check whether point P(x, y) lies inside the triangle formed 
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);
 
   /* Calculate area of triangle PBC */  
   float A1 = area (x, y, x2, y2, x3, y3);
 
   /* Calculate area of triangle PAC */  
   float A2 = area (x1, y1, x, y, x3, y3);
 
   /* Calculate area of triangle PAB */   
   float A3 = area (x1, y1, x2, y2, x, y);
   
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}
int main()
{
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   int x1,x2,x3,y1,y2,y3;
   cin>>x1>>y1;
   cin>>x2>>y2;
   cin>>x3>>y3;
   //cout<<x1<<x2<<x3;
   //cout<<y1<<y2<<y3;
   double d1=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
   double d2=sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
   double d3=sqrt((y2-y3)*(y2-y3)+(x2-x3)*(x2-x3));
   double sl1=-(y2-y1)/(x2-x1);
   double sl2=-(y2-y3)/(x2-x3);
   double sl3=-(y3-y1)/(x3-x1);
   //cout<<d2<<d1<<d3;
   double c1=y2-sl1*x2;
   double c2=y3-sl2*x3;
   double c3=y1-sl1*x1;
   //cout<<(y2-y1)/(x2-x1)<<sl1<<sl3;
   if(d1+d2>d3&&d2+d3>d1&&d1+d3>d2)
   {
      if(isInside(x1,y1,x2,y2,x3,y3,0,0)==true||(c1==0)||(c2==0)||(c3==0))
      {
         cout<<"Yes\n";
      }
      else
      {
         cout<<"No\n";
      }
   }
   else
   {
      cout<<"Invalid\n";
   }
   return 0;
}
