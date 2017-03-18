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
int arr[10005];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	printf("%.2lf ",(double)arr[0]);
	vector <int > v;
	v.push_back(arr[0]);
	for(i=1;i<n;i++)
	{
		v.push_back(arr[i]);
		sort(v.begin(),v.end());
		if((i+1)%2==0)
		{
			printf("%.2lf ",(double)(v[(i/2)]+v[(i+1)/2])/2);
		}
		else
		{
			printf("%.2lf ",(double)v[(i/2)]);
		}
	}
	return 0;
}
