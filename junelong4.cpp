#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define pb push_back
#define bp(x) __builtin_popcount(x)
typedef long long int ll;
int a[6]={8,0,2,4,6,8};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int t,i,temp,z;
	ll nth;
	cin>>t;
	for(z=0;z<t;z++)
	{
		vector <int > lis;
		cin>>nth;
		while(nth>5)
		{
			if(nth%5==0)
			{
				lis.pb(a[5]);
				nth=nth/5;
			}
			else if(nth%5!=0)
			{
				temp=nth%5;
	    		lis.pb(a[temp]);
	    		nth=(nth/5)+1;
	    	}
		}
		if(nth<=5)
			lis.pb(a[nth]);
		for(i=lis.size()-1;i>=0;i--)
			cout<<lis[i];
		cout<<"\n";
	}
	return 0;
}
