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
int isleap(int y){
	if(y%400==0||(y%4==0&&y%100!=0))
		return 2;
	else 
		return 1;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	int y;
	cin>>y;
	int n=1,s=isleap(y),sum=0;
	y++;
	while(true)
	{
		n=isleap(y);
		sum+=n;
		if(sum%7==0&&n==s)
			break;
		y++;
	}
	cout<<y<<"\n";
	return 0;
}