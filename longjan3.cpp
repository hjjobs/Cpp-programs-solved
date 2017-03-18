#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define pb push_back
#define bp(x) __builtin_popcount(x)
typedef long long int ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
priority_queue<int> pq;
queue<int> q1,q;
vector<int> v[50010];
map<int,int> mp;
set<int> st[50010];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int ans[50010]={0};
        int arr[50010]={0};
        int capital=50001;
        int n,i,j,x,y;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            pq.push(arr[i]);
            mp[arr[i]]=i;
            if(arr[i]>arr[capital])
                capital=i;
        }
        for(i=0;i<n-1;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
            ans[i+1]=capital;
        }
        ans[n]=capital;
        q1.push(capital);
        st[capital].insert(arr[capital]);
        for(i=0;i<v[capital].size();i++)
        {
            st[capital].insert(arr[v[capital][i]]);
            q1.push(v[capital][i]);
            st[v[capital][i]].insert(arr[v[capital][i]]);
            for(j=0;j<v[v[capital][i]].size();j++)
            {
                st[v[capital][i]].insert(arr[v[v[capital][i]][j]]);
            }
        }
        y=capital;
        while(!q1.empty())
        {
            x=q1.front();
            while(ans[x]==y)
            {
                capital=pq.top();
                if(st[x].count(capital))
                {
                    q.push(capital);
                    pq.pop();
                }
                else
                {
                    ans[x]=mp[capital];
                    while(!q.empty())
                    {
                        pq.push(q.front());
                        q.pop();
                    }
                }
            }
            q1.pop();
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        while(!pq.empty())
        {
            pq.pop();
        }
        while(!q.empty())
        {
            q.pop();
        }
        while(!q1.empty())
        {
            q1.pop();
        }
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            st[i].clear();
        }
        mp.clear();
    }
    return 0;
}