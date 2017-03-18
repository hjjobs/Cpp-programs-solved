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
	int n;
	while(cin>>n)
	{
		int arr1[10003]={0};
		int arr2[10003]={0};
		int arr[10003]={0};
		int i,j,temp1;
		ll sum=0;
		int temp=INT_MAX;
		for(i=0;i<n;i++)
		{
			cin>>arr1[i]>>arr2[i];
		}
		for(i=0;i<n;i++)
		{
			if(arr[i]!=1)
			{
			temp=INT_MAX;
			sum+=arr2[i];
			for(j=i+1;j<n;j++)
			{
				if(arr[j]!=1)
				{
					if(temp>=arr1[j])
					{
						temp=arr1[j];
						//cout<<temp<<" ";
						temp1=j;
					}
				}
			}
			arr[temp1]=1;
			sum=sum+arr1[temp1];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
