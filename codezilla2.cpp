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
#define INF 0x3f3f3f3f
#define ll long long

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
	int nt, n, Q, x;
	int factors[100], f, F;
	int m;
	ll ans;
	scanf("%d%d", &n, &Q);
	m = n % x;
	if (m == 0) 
	{
		f = 0;
		n /= x;
		for (int i = 2; i * i <= n; i++)
		if (n % i == 0) 
		{
			factors[f++] = i;
			while (n % i == 0) n /= i;
		}
		if (n > 1) factors[f++] = n;
		F = 1 << f;
		assert(f <= 20);
	}
	while (Q--) 
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (m != 0) { printf("0\n"); continue; }
		l = l / x + (l % x != 0);
		r = r / x;
		if (l > r) { printf("0\n"); continue; }
		ans = r - l + 1;
		for (int S = 1; S < F; S++) 
		{
			int num = 1, cnt = 0;
			for (int i = 0; i < f; i++)
				if (S & (1 << i)) {
					cnt++;
					num *= factors[i];
				}
			if (cnt & 1) ans -= r / num - (l - 1) / num;
			else ans += r / num - (l - 1) / num;
		}
		printf("%lld\n", ans);
	}
	return 0;
}