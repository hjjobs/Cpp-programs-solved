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
		int a[25][25];
		int arr[25]={0};
		int n,k,i,j,ans=5000;
		memset(a,0,sizeof(a));
		bool flag=false;
		cin>>n>>k;
		for(i=0;i<n;i++)
			for(j=0;j<k;j++)
				cin>>a[i][j];
		for(i=0;i<k;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][i]==1)
				{
					arr[i]=arr[i]|1<<j;
				}
			}
		}
		for(i=0;i<(1<<k);i++)
		{
			int sum = 0;
            for(j = 0;j<k;++j)
            {
                if(i&(1<<j))
                {
                    sum=sum|arr[j];
                }
            }
            if(sum==(1<<n)-1){
                flag= true;
                ans = min(ans,__builtin_popcount(i));
            }
        }
        if(!flag)
        	cout<<"-1\n";
        else 
        	cout<<ans<<"\n";
	}
	return 0;
}
