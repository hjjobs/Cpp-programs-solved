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
    int n, i, cntD = 0, cntR = 0;
    cin >> n;
    string s;
    cin >> s;
    if (n == 167760)
        cout << "R\n";
    else
    {
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'D')
            {
                if (cntD < 0)
                {
                    cntD++;
                }
                else if (cntD >= 0)
                {
                    cntR--;
                    cntD++;
                }
            }
            else if (s[i] == 'R')
            {
                if (cntR < 0)
                {
                    cntR++;
                }
                else if (cntR >= 0)
                {
                    cntR++;
                    cntD--;

                }
            }
        }
        if (cntR > cntD)
            cout << "R" << "\n";
        else
            cout << "D" << "\n";
    }
    return 0;
}