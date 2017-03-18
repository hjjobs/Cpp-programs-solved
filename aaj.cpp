#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
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
        int nodes, edges, x, y;
        long long weight, minimumCost;
        int temp,n,c=0;
        ll sum=0;
        int flag=0;
        int temp1=0;
        cin>>n;
        int a[n+5][n+5];
        for(i=0;i<n;i++)
        {
            temp1=0;
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                temp1=temp1+a[i][j];
            }
            if(temp1-a[i][i]==0)
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
                    
                    sum=sum+a[i][j];
                    adj[i].push_back(make_pair(weight, j));
                    adj[j].push_back(make_pair(weight, i));
                }
            }
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y >> weight;
            
        }
        // Selecting 1 as the starting node
        minimumCost = prim(1);
        cout << minimumCost << endl;
    return 0;
}