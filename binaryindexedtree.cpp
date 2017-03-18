#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pii pair<int,int>
#define mod 1000000007
typedef long long int ll;
int BIT[1000], a[1000], n;
void update(int x, int val)
{
      while(x <= n)
      {
      	BIT[x] += val;
      	x += x&(-x);
      }  
}
void update(int i, int j, int v)	{
	update(i, v);
	update(j + 1, -v);
}
int query(int x)
{
     int sum = 0;
     while(x > 0)
     {
     	sum += BIT[x];
     	x -= x&(-x);
     } 
     return sum;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	scanf(“%d”, &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf(“%d”, &a[i]);
           update(i, a[i]);
     }
     printf(“sum of first 10 elements is %d\n”, query(10));
     printf(“sum of all elements in range [2, 7] is %d\n”, query(7) – query(2-1));
	return 0;
}