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
double A=(sqrt(5)+1)/2;
double B=(1-sqrt(5))/2;
int a[100005]={0};
double tree[500006];
double tree2[500006];
double ipow(double a, int b)
{
    double y=a,x=1; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            while(x>mod) x-=mod;
        }
        y = (y*y);
        while(y>mod) y-=mod; 
        b /= 2;
    }
    return x;
}
long long int fibonacci(int n)
{
    long long fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j]);
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j]);
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1]);
}
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = (ipow(A,a[start])+1);
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] * tree[2*node+1];
        tree[node]-=(int)(tree[node]/mod)*mod;
    }
}
void build2(int node, int start, int end)
{
    if(start == end)
    {
        tree2[node] = (ipow(B,a[start])+1);
    }
    else
    {
        int mid = (start + end) / 2;
        build2(2*node, start, mid);
        build2(2*node+1, mid+1, end);
        tree2[node] = tree2[2*node] * tree2[2*node+1];
        tree2[node]-=(int)(tree2[node]/mod)*mod;
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        a[idx]=val;
        tree[node]=(ipow(A,val)+1);
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] * tree[2*node+1];
        tree[node]-=(int)(tree[node]/mod)*mod;
    }
}
void update2(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        a[idx]=val;
        tree2[node]=(ipow(B,val)+1);
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update2(2*node, start, mid, idx, val);
        }
        else
        {
            update2(2*node+1, mid+1, end, idx, val);
        }
        tree2[node] = tree2[2*node] * tree2[2*node+1];
        tree2[node]-=(int)(tree2[node]/mod)*mod;
    }
}
double query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 1;
    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    double p1 = query(2*node, start, mid, l, r);
    double p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 * p2);
}
double query2(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 1;
    }
    if(l <= start and end <= r)
    {
        return tree2[node];
    }
    int mid = (start + end) / 2;
    double p1 = query2(2*node, start, mid, l, r);
    double p2 = query2(2*node+1, mid+1, end, l, r);
    return (p1 * p2);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,i,j,l,r;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    build(1,0,n-1);
    build2(1,0,n-1);
    for(j=0;j<m;j++)
    {
        char z;
        cin>>z;
        if(z=='Q')
        {
            double sum1,sum2;
            cin>>l>>r;
            l--;r--;
            sum1=query(1,0,n-1,l,r);
            sum2=query2(1,0,n-1,l,r);
            //cout<<sum1<<sum2<<"\n";
            double ans;
            ans=(sum1-sum2)/sqrt(5);
            while(ans<0) ans+=mod;
            ans-=(int)(ans/mod)*mod;
            cout<<ans<<"\n";
        }
        else
        {
            cin>>l>>r;
            l--;
            a[l]=r;
            update(1,0,n-1,l,r);
            update2(1,0,n-1,l,r);
        }
    }
    return 0;
}
