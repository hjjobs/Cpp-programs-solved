#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pii pair<int,int>
#define m_p make_pair
#define mod 1000000007
#define F first
#define S second

typedef long long int ll;

int R, C, ans, len;
char grid[1001][1001];
int visited[1001][1001];
int dist[1001][1001];
int dr[4] = {0, 0, 1,-1};
int dc[4] = {1,-1, 0, 0};

pair<int,int> diameterEnd;


bool inGrid(pair<int,int>& g)
{
    return (g.F>=0 && g.F<R && g.S>=0 && g.S<C);
}

void bfs(pair<int,int> start)
{
    queue<pair<int,int> > q;
    q.push(start);
    while(!q.empty())
    {
        pair<int,int> cur = q.front(),next;
        q.pop();
        for(int i=0;i<4;i++)
        {
            next.F = cur.F + dr[i];
            next.S = cur.S + dc[i];
            if(inGrid(next))
            {
                if(grid[next.F][next.S] == '.' && !visited[next.F][next.S])
                {
                    visited[next.F][next.S] = 1;
                    dist[next.F][next.S] =  dist[cur.F][cur.S] + 1;
                    if(dist[next.F][next.S]>len)
                    {
                        len = dist[next.F][next.S];
                        diameterEnd = next;
                    }
                    q.push(next);
                }

            }
        }

    }
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
    int t,i,j,present,z;
    cin>>t;
    for(z=0;z<t;z++)
    {
        len = 0;
        present = 0;
        pair<int,int>  St;
        cin>>C>>R;
        memset(visited,0,sizeof visited);
        for(i=0;i<R;i++)
        {
            cin>>grid[i];
        }
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(grid[i][j] == '.')
                {
                    St = m_p(i,j);
                    dist[i][j] = 0;
                    present = 1;
                    break;
                }
            }
            if(present)
                break;
        }
        bfs(St);
        memset(visited,0,sizeof visited);
        dist[diameterEnd.F][diameterEnd.S] = 0;
        len = 0;
        bfs(diameterEnd);
        printf("Maximum rope length is %d.\n",len);
    }
    return 0;
}