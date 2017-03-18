//http://stackoverflow.com/questions/622287/area-of-intersection-between-circle-and-rectangle
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
double sec(double h, double r = 1) 
{
    assert(r >= 0);
    return (h < r)? sqrt(r * r - h * h) : 0; 
}
double g(double x, double h, double r = 1)
{
    return .5f * (sqrt(1 - x * x / (r * r)) * x * r + r * r * asin(x / r) - 2 * h * x); // http://www.wolframalpha.com/input/?i=r+*+sin%28acos%28x+%2F+r%29%29+-+h
}
double intersectarea(double x0, double x1, double h, double r)
{
    if(x0 > x1)
        std::swap(x0, x1);
    double s = sec(h, r);
    return g(max(-s, min(s, x1)), h, r) - g(max(-s, min(s, x0)), h, r); 
}
double intersectarea(double x0, double x1, double y0, double y1, double r) 
{
    if(y0 > y1)
        std::swap(y0, y1);
    if(y0 < 0) {
        if(y1 < 0)
            return intersectarea(x0, x1, -y0, -y1, r);
        else
            return intersectarea(x0, x1, 0, -y0, r) + intersectarea(x0, x1, 0, y1, r);
    } else {
        assert(y1 >= 0);
        return intersectarea(x0, x1, y0, r) - intersectarea(x0, x1, y1, r);
    }
}
double intersectarea(double x0, double x1, double y0, double y1, double cx, double cy, double r) 
{
    x0 -= cx; x1 -= cx;
    y0 -= cy; y1 -= cy;
    return intersectarea(x0, x1, y0, y1, r);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,q,i,j;
    double xx[50005];
    double yy[50005];
    double rr[50005];
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>xx[i]>>yy[i]>>rr[i];
    }
    for(i=0;i<q;i++)
    {
        double t1,t2,t3,t4;
        double sum=0.0;
        cin>>t1>>t2>>t3>>t4;
        for(j=0;j<n;j++)
        {
            sum=sum+intersectarea(t1,t3,t2,t4,xx[j],yy[j],rr[j]);
        }
        //cout<<sum<<"\n";
        printf("%.6lf\n",sum);
    }
    return 0;
}