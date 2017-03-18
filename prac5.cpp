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
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i,j;
	int arr[100];
	cin>>n;
	arr[0]=1;
	i=0;
	while(arr[i]<=1000000)
	{
		arr[i+1]=arr[i]*10;
		arr[i+1]=arr[i]*10+1;
		i++;
	}
	
	return 0;
}
