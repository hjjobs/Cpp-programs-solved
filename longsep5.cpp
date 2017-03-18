//https://github.com/leninkumar31/LENIN/blob/master/SEGMENT%20TREE/GSS4.cpp
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
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

bool isprime[1000102];
ll fac[1000102];
ll a[100005];
ll n;
void sieve()
{
	for(int i=0;i<=1000050;i++)
		isprime[i]=true;
	isprime[0]=false;
	isprime[1]=false;
	fac[0]=1;
	fac[1]=1;
	for(int i=2;i*i<1000050;i++)
	{
		if(isprime[i])
		{
			//fac[i]=i;
			for(int j=2;i*j<1000050;j++)
			{
				if(isprime[i*j])
				{
					fac[i*j]=i;
				}
				isprime[i*j]=false;
			}
		}
	}
	for(int i=2;i<=1000050;i++)
	{
		if(isprime[i])
			fac[i]=i;
	}
}
struct node {
	ll sum;
	bool flag;
	void merge(node l, node r) {
		sum = max(l.sum,r.sum);
		flag = (l.flag && r.flag);
	}
};
node segment[3000005];
//int N = 2 * pow(2, ceil(log2(n))) - 1;
//building segment tree
void build(int low, int high, int s) {
	if (low == high) {
		segment[s].sum = fac[a[low]];
		if (fac[a[low]] == 1)
			segment[s].flag = true;
		else
			segment[s].flag = false;
		return;
	}
	int mid = (low + high) / 2;
	build(low, mid, 2 * s + 1);
	build(mid + 1, high, 2 * s + 2);
	segment[s].merge(segment[2 * s + 1], segment[2 * s + 2]);
}
//querying segment tree
ll query(int low, int high, int left, int right,int s) {
	//no overlap
	if (left > high || right < low||low<0||high>n-1)
		return 0;
	//total overlap
	if (left <= low && right >= high)
		return segment[s].sum;
	//partial overlap
	int mid = (low + high) / 2;
	ll lval = query(low, mid, left, right, 2 * s + 1);
	ll rval = query(mid + 1, high, left, right, 2 * s + 2);
	return max(lval,rval);
}
//updating segment tree
void update(int low, int high, int left, int right,int s) {
	//no overlap
	if (left > high || right < low||low<0||high>n-1)
		return;
	//if node is true we don need to update
	if (segment[s].flag)
		return;
	//if it is leaf
	if (low == high) {
		if (fac[a[low]] == 0)
			return;
		a[low] = a[low]/fac[a[low]];
		segment[s].sum = fac[a[low]];
		if (fac[a[low]] == 1)
			segment[s].flag = true;
		return;
	}
	//if it is not leaf
	int mid = (low + high) / 2;
	if (mid >= right)
		update(low, mid, left, right, 2 * s + 1);
	else if (mid < left)
		update(mid + 1, high, left, right, 2 * s + 2);
	else {
		update(low, mid, left, right, 2 * s + 1);
		update(mid + 1, high, left, right, 2 * s + 2);
	}
	segment[s].merge(segment[2 * s + 1], segment[2 * s + 2]);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,i,j;
		scanf("%d",&n);
		scanf("%d",&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int typ,l,r;
		build(0, n-1, 0);
		for(i=0;i<m;i++)
		{
			scanf("%d",&typ);
			if(typ==0)
			{
				scanf("%d",&l);
				scanf("%d",&r);
				update(0, n-1,l-1,r-1,0);
			}
			else
			{
				scanf("%d",&l);
				scanf("%d",&r);
				printf("%lld ",query(0, n-1,l-1,r-1, 0));
			}
		}
		printf("\n");
	}
	return 0;
}
