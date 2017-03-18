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
int solve(int arr[], int n, int sum)
{
    map<int, int> m;
    for (int i=0; i<n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
    for (int i=0; i<n; i++)
    {
        twice_count += m[sum-arr[i]];
        if (sum-arr[i] == arr[i])
            twice_count--;
    }
    return twice_count/2;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int arr[100005];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int ans=0;
        for(i=1;i<17;i++)
        {
            int val=1<<i;
            ans+=solve(arr, n, val);
        }
        cout<<ans<<"\n";
    }
    return 0;
}