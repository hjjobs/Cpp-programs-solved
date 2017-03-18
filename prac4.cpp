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
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i,lo,hi;
	int arr[100005];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	lo=0;
	hi=n-1;
	int count=0;
	while(lo<=hi)
	{
		int temp1,temp2,temp3;
		temp1=arr[hi]-2*arr[lo+1];
		temp2=arr[hi-1]-2*arr[lo];
		temp3=arr[hi]-2*arr[lo];
		if(temp3<=0)
		{
			cout<<count;
			break;
		}
		if(temp1==arr[hi]-2*arr[lo])
		{
			lo++;
			continue;
		}
		if(temp2==arr[hi]-2*arr[lo])
		{
			hi--;
			continue;
		}
		if(temp1<=0||temp2<=0)
		{
			cout<<count+1;
			break;
		}
		if(temp1<temp2)
		{
			hi--;
			count++;
		}
		else
		{
			lo++;
			count++;
		}
	}
	return 0;
}
