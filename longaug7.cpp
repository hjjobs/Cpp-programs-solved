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
string a;
int arr[1000005]={0};
int arr1[1000005]={0};
int amazingness(string st)
{
	memset(arr,0,sizeof(arr));
    int ans = 0;
    for (int i=0;i<st.length();i++) 
    {
         int val = 0;
         for ( int j = i; j < st.length(); j++ ) 
         {
            val=(val^(st[j]-'0'));
            //cout<<val<<" ";  
            if(arr[val]==0) 
            {
                 ans=(ans+val)%mod;
                 arr[val]=1;
            }
         }
   }
   return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	arr1[0]=0;
	for(int i=1;i<=1000001;i++)
	{
		
		a=to_string(i);
		//cout<<a<<" ";
		//cout<<a.length();
		//cout<<amazingness(a)<<" ";
		arr1[i]=(arr[i-1]+(amazingness(a))%mod)%mod;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int l,r,i;
		cin>>l>>r;
		cout<<arr[r]-arr[l-1]<<"\n";
	}
	return 0;
}