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
        int n,m,i,j;
        char a[1005][1005];
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(a[i][0]=='W'||a[i][m-1]=='W')
            {
                flag=1;
                break;
            }
        }
        for(j=0;j<m;j++)
        {
            if(a[n-1][j]=='A'&&(a[n-2][j]=='B'||a[n-2][j]=='W'))
            {
                flag=1;
                break;
            }
            else if(a[n-1][j]=='W')
            {
                flag=1;
                break;
            }
        }
        for(i=0;i<n-1;i++)
        {
            for(j=1;j<m-1;j++)
            {
                if(a[i][j]=='W'&&(a[i][j+1]=='A'||a[i][j-1]=='A'||a[i+1][j]=='A'))
                {
                    flag=1;
                    break;
                }
                else if(a[i][j]=='B'&&(a[i+1][j]=='W'||a[i+1][j]=='A'))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==1)
        {
            cout<<"no\n";
        }
        else
        {
            cout<<"yes\n";
        }
    }
    return 0;
}