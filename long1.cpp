#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
#define pb push_back
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
		char a[100005];
		int arr[3]={0};
		int n,i,ans;
		cin>>n;
		cin>>a;
		for(i=0;i<n;i++)
		{
			if(a[i]=='R')
				arr[0]++;
			else if(a[i]=='G')
				arr[1]++;
			else
				arr[2]++;
		}
		if(arr[0]>=arr[1]&&arr[0]>=arr[2])
			ans=arr[1]+arr[2];
		else if(arr[2]>=arr[1]&&arr[2]>=arr[0])
			ans=arr[1]+arr[0];
		else if(arr[1]>=arr[0]&&arr[1]>=arr[2])
			ans=arr[0]+arr[2];
		cout<<ans<<"\n";
	}
	return 0;
}
