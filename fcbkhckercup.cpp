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
ll arr[1000005];
pair <ll, ll> pp[1000005];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, j;
    ll l, r;
    cin >> n >> l >> r;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (i = 0; i < n - 1; i++)
    {
        ll t1 = arr[i] + arr[i + 1] - 1;
        ll t2 = arr[i + 1] - arr[i] + 1;
        pp[i].first = t2;
        pp[i].second = t1;
    }
    sort(pp, pp + n - 1);
    if (pp[0].first < l)
        pp[0].first = l;
    if (pp[0].second > r)
        pp[0].second = r;
    for (i = 1; i < (n - 1); i++) 
    {
        if (pp[i].first < l)
            pp[i].first = l;
        if (pp[i].second > r)
            pp[i].second = r;
        if (pp[i].first <= pp[i - 1].second)
            pp[i].first = pp[i - 1].second + 1;
        if (pp[i].second < pp[i - 1].second)
            pp[i].second = pp[i - 1].second;
    }
    ll ans = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (pp[i].second - pp[i].first + 1 > 0)
            ans = ans + (pp[i].second - pp[i].first + 1);
    }
    cout << ans << "\n";
    return 0;
}