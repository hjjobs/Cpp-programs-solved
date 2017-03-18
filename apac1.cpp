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
	int t,z;
	cin>>t;
	for(z=1;z<=t;z++)
	{
		pair <int,string> arr[110];
		int n,i,j;
		string b;
		cin>>n;
		getline(cin,b);
		for(i=0;i<n;i++)
		{
			int hash[30]={0};
			string a;
			getline(cin,a);
			//cout<<a<<"\n";
			//a.erase(std::remove_if(a.begin(), a.end(), std::isspace), a.end());
			for(j=0;j<a.length();j++)
			{
				if(a[j]!=' ')
					hash[a[j]-'A']++;
			}
			int count=0;
			for(j=0;j<26;j++)
			{
				if(hash[j]>=1)
					count++;
			}
			arr[i].first=-(count);
			arr[i].second=a;
		}
		sort(arr,arr+n);
		cout<<"Case #"<<z<<": "<<arr[0].second<<"\n";
	}
	return 0;
}
