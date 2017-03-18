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

int TYE[10000000];
vector < pair < int , int > > test;
int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	for(int i=0;i<10000000;i++)
		TYE[i]=-1;
	int c,n;
	cin>>n;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		string input;
		cin>>input;
		if(input=="PUT")
		{

			int value;
			cin>>value;
			//cout<<value<<endl;
			char com;
			cin>>com;
			int bekar;
			cin>>bekar;
			TYE[value]=i;
			
		}
		if(input=="GET")
		{
			int value;
			cin>>value;
			TYE[value]=i;
		}
	}
	for(int i=0;i<10000000;i++)
	{
		if(TYE[i]!=-1)
			test.push_back(make_pair(TYE[i],i));
	}
	if(test.size()>n)
		cout<<n<<endl;
	else cout<<test.size()<<endl;
	sort(test.begin(),test.end());
	int start=test.size()>n?test.size()-n:0;
	for(int i=start;i<test.size();i++)
		cout<<test[i].second<<" ";

}