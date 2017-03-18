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
int G[1005][1005];
int n;
int V=n;
int colorArr[1001];
bool isBipartite(int src)
{
    colorArr[src] = 1;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    G[i][j]=1;
                    G[j][i]=1;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
        	int u,v;
            cin>>u>>v;
            u--;
            v--;
            G[v][u]=0;
            G[u][v]=0;
        }
        bool flag=true;
        for(int i=0;i<n;i++)
        {
        	colorArr[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
        	if(colorArr[i]==-1 && !isBipartite(i))
        	{
        		flag=false;
        	}
        }
        if(flag==false)
        {
        	cout<<"NO\n";
        }
        else
        {
        	cout<<"YES\n";
        }

	}
	return 0;
}
