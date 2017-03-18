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
multiset < string > v;
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	int arr[100];
	arr[1]=3;
	arr[2]=9;
	for(int i=3;i<t;i++)
	{
		arr[i]=2*arr[i-1]+arr[i-2];
	}
		cout<<arr[6]<<" ";
		cout<<arr[7]<<" ";
		cout<<arr[15]<<" ";
		cout<<arr[78]<<" ";
		cout<<arr[3]<<" ";
		cout<<arr[4]<<" ";
		cout<<arr[5]<<" ";
	return 0;
}
