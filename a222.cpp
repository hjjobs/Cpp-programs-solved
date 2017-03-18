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
long long int MOD = (1000000007);
ll f[500009];
long long power(ll a, ll b, ll MOD)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > MOD) x %= MOD;
        }
        y = (y * y);
        if (y > MOD) y %= MOD;
        b /= 2;
    }
    return x;
}
long long InverseEuler(ll n, ll MOD)
{
    return power(n, MOD - 2, MOD);
}

void fact()
{
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 500005; i++)
        f[i] = (f[i - 1] * i) % MOD;
}
long long int C(int n, int r, ll MOD)
{
    //vector<long long> f(n + 1,1);
    return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
}
ll a[500005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fact();
    int n, k, x, i, id;
    cin >> n >> k >> x;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long int ans = 0;
    for (i = k; i <= n; i++)
    {
        ll y = a[i] - x;
        //cout<<y<<"\n";
        if (y < 1)
        {
            ans = ans + C(i - 1, k - 1, MOD);
        }
        else
        {
            id = lower_bound(a + 1, a + i, y) - a;
            //cout<<id<<"\n";
            int nu = (i - id);
            if (a[i] - a[id] <= x)
            {
                ans = (ans + C(i - id, k - 1, MOD)) % MOD;
                //cout<<ans<<"\n";
            }                           `
            else
            {
                id = id + 1;
                //cout<<C(i-id,k-1,MOD)<<"\n";
                ans = (ans + C(i - id, k - 1, MOD)) % MOD;
                //cout<<ans<<"\n";
                //ans=(ans+(fac[i-id]*(c[k-1]*c[i-id-k+1])%mod)%mod)%mod;
            }
        }
        //cout<<ans<<"\n";
        //ans=(ans+ncr(i-id,k-1))%(mod);
        //cout<<ans<<"\n";
    }
    cout << ans << "\n";
    return 0;
}
