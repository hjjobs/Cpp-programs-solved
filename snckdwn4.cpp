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
	int t;
	cin>>t;
	while(t--)
	{
		int i,n,j;
		ll arr[105];
		ll arr1[105][6];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			arr1[i][0]=floor(log(arr[i])/log(2))+1;
			arr1[i][1]=floor(log(arr[i])/log(3))+1;
			arr1[i][2]=floor(log(arr[i])/log(4))+1;
			arr1[i][3]=floor(log(arr[i])/log(5))+1;
			arr1[i][4]=floor(log(arr[i])/log(6))+1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			{
				cout<<arr1[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
