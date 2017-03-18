#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
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
	//freopen("output.txt","w",stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[100005];
		int i;
		int cnt = 0;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 0)
				cnt++;
		}
		int k = n;
		for (i = 0; i < n; i++)
		{
			if (a[i] == 0)
			{
				k = i;
				break;
			}
		}
		cout << (1000 * cnt) + (100 * (n - k)) << "\n";
	}
	return 0;
}