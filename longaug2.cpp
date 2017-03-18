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
pair<ll,pair<ll,ll> > vv[100005];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int flag;
	ll n,w,l,i,t1,t2,temp,temp1=0,sum1,sum2=0,max1,ans,min,sum11=0;
	cin>>n>>w>>l;
	if(n<=10000&&w<=10000&&l<=10000)
	{
	flag=0;
	for(i=0;i<n;i++)
	{
		cin>>t1>>t2;
		if(l-t1>=0)
		{
			temp=((l-t1)/t2);
			if(((l-t1)%t2)!=0)
				temp+=1;
		}
		else
		{
			temp=0;
		}
		temp1=t1+temp*t2;
		vv[i].first=temp;
		vv[i].second.first=temp1;
		vv[i].second.second=t2;
		sum1+=vv[i].second.first;
		vv[i].second.first=t1;
		sum2+=vv[i].second.second;
	}
	sort(vv,vv+n);
	/*for(i=0;i<n;i++)
	{
		cout<<vv[i].first<<" "<<vv[i].second.first<<" "<<vv[i].second.second<<"\n";
	}*/
	sum1=0;
	max1=vv[n-1].first;
	min=vv[i].first;
	while(true)
	{
		sum11=0;
		for(i=0;i<n;i++)
		{
			if((vv[i].second.first+min*vv[i].second.second)>=l)
				sum11+=vv[i].second.first+min*vv[i].second.second;
			if(sum11>=w)
			{	flag=1;
				break;
			}
		}
		if(flag==1)
			break;
		min++;
	}
	cout<<min<<"\n";
	if(flag==0)
	{
		for(i=0;i<n;i++)
		{
			if(max1>vv[i].first)
			{
				sum1+=((vv[i].second.second)*(max1-vv[i].first));
			}
		}
		ans=((w-sum1)/sum2);
		if((w-sum1)%sum2!=0)
		{
			ans+=1;
		}
		cout<<max1+ans<<"\n";
	}
}
else
{
	flag=0;
	for(i=0;i<n;i++)
	{
		cin>>t1>>t2;
		if(l-t1>=0)
		{
			temp=((l-t1)/t2);
			if(((l-t1)%t2)!=0)
				temp+=1;
		}
		else
		{
			temp=0;
		}
		temp1=t1+temp*t2;
		vv[i].first=temp;
		vv[i].second.first=temp1;
		vv[i].second.second=t2;
	}
	sort(vv,vv+n);
	/*for(i=0;i<n;i++)
	{
		cout<<vv[i].first<<" "<<vv[i].second.first<<" "<<vv[i].second.second<<"\n";
	}*/
	sum1=0;
	max1=vv[n-1].first;
	for(i=0;i<n;i++)
	{
		sum1+=vv[i].second.first;
		sum2+=vv[i].second.second;
		if(sum1>=w)
		{
			max1=vv[i].first;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		for(i=0;i<n;i++)
		{
			if(max1>vv[i].first)
			{
				sum1+=((vv[i].second.second)*(max1-vv[i].first));
			}
		}
		ans=((w-sum1)/sum2);
		if((w-sum1)%sum2!=0)
		{
			ans+=1;
		}
		cout<<max1+ans<<"\n";
	}
	else
	{
		cout<<max1<<"\n";
	}
}
	return 0;
} 