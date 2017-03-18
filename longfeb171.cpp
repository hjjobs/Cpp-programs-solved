#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define pb push_back
#define bp(x) __builtin_popcount(x)
#define pi 3.14159265
typedef long long int ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        int arr[505][505]={0};
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        int ans=0;
        int flag=0;
        int val=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]==0)
                {
                    val=abs(i-j);
                }
                if(val==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                ans=0;
                break;
            }
            else
                ans=max(val,ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}