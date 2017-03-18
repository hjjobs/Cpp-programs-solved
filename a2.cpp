#include <bits/stdc++.h>
 
using namespace std;
 
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
typedef long long int ll;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
int c;
void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}
 
int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
 
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
 
long long kruskal(pair<long long int, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }   
    }
    return minimumCost;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    int t,i,j;
    cin>>t;
    while(t--)
    {
        pair <long long int, pair<int, int> > p[MAX];
        int temp,n,c=0;
        ll sum=0;
        int flag=0;
        int temp1=0;
        cin>>n;
        long long int a[n+5][n+5];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                sum=sum+a[i][j];
            }
        }
        if(n==1)
        {
        	cout<<sum<<"\n";
        }
        else
        {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(!(a[i][j]==0||a[j][i]==0))
                a[i][j]=min(a[i][j],a[j][i]);
            }
        }
        for(i=0;i<n;i++)
        {
            temp1=0;
            for(j=0;j<n;j++)
            {
                temp1=temp1+a[i][j]+a[j][i];
            }
            if(temp1-2*a[i][i]==0)
            {
                flag=1;
                cout<<"-1\n";
                break;
            }
        }
        if(flag!=1)
        {
             
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                        if(a[i][j]!=0)
                        {
                        p[c] = make_pair(a[i][j], make_pair(i, j));
                        c++;
                    }
              
                }
            }
                int x, y;
                long long int weight, cost, minimumCost;
                initialize();
                edges=c;
                nodes=n;
                sort(p, p+c);
                minimumCost = kruskal(p);
                cout << sum-minimumCost << endl;
        }
    }
    }
    return 0;
}