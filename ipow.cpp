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
int ipow(int base,long long int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result=(result*base)%1000000007;
        exp >>= 1;
        base *= base;
    }

    return result;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long long int i,t,n,sum;
	cin>>t;
	for(i=0;i<t;i++)
	{
		sum=0;
		cin>>n;
		sum=(n+(5*((ipow(10,n+1)-10)/9-n)%1000000007)/9)%1000000007;
		cout<<sum<<"\n";
	}
	return 0;
}