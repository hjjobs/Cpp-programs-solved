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
long double dp[410][24][24];
long double pr[410][24][24];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    memset(dp, 0.0, sizeof(dp));
    int sum = 405;
    for (int ii = 1; ii < 21; ii++)
    {
        dp[0][0][ii] = 1.0;
        for (int j = 1; j <= 21; j++)
        {
            for (int i = 1; i <= sum; i++)
            {
                for (int k = 1; k <= ii; k++)
                {
                    if (i >= k)
                        dp[i][j][ii] = dp[i][j][ii] + (dp[i - k][j - 1][ii]) / (ii * 1.0);
                }
                pr[i][j][ii] = pr[i - 1][j][ii] + dp[i][j][ii];
            }
        }
    }
    for (int pp = 1; pp <= t; pp++)
    {
        double final = 0.0;
        int h, s, i, k;
        string arr[25];
        int x[25] = {0};
        int y[25] = {0};
        int z[25] = {0};
        int op[25] = {0};
        cin >> h >> s;
        for (i = 0; i < s; i++)
        {
            cin >> arr[i];
            int c = 0;
            for (k = 0; k < arr[i].length(); k++)
            {
                if ((arr[i][k] < '0') || (arr[i][k] > '9'))
                {
                    c++;
                    if (arr[i][k] == '-')
                        op[i] = 1;
                    else if (arr[i][k] == '+')
                        op[i] = -1;
                    continue;
                }
                if (c == 0)
                {
                    x[i] = x[i] * 10 + arr[i][k] - '0';
                }
                if (c == 1)
                {
                    y[i] = y[i] * 10 + arr[i][k] - '0';
                }
                if (c == 2)
                {
                    z[i] = z[i] * 10 + arr[i][k] - '0';
                }
            }
            z[i] = z[i] * op[i];
            //cout << "## " << x[i] << " " << y[i] << " " << z[i] << endl;
            double val = 0.0;
            int k = max(1, h + z[i]);
            z[i] = z[i] * -1;
            if (z[i] >= h)
            {
                val = 1.000000;
            }
            else if (k > x[i]*y[i])
            {
                val = 0.000000;
            }
            else
                val = pr[x[i]*y[i]][x[i]][y[i]] - pr[k-1][x[i]][y[i]];
            if (val > final)
            {
                final = val;
            }
        }
        cout << "Case #" << pp << ": ";
        printf("%.6lf\n", final);
    }
    return 0;
}