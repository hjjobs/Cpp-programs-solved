#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define pb push_back
#define bp(x) __builtin_popcount(x)
typedef long long int ll;
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	string s;
    cin>>s;
    int n,i,j;
    cin>>n;
    string a[3005];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int len=s.length();
    for(i=0;i<len;i++)
    {
        if(s[i]=='*')
        {
            for(j=0;j<n;j++)
            {
                a[j][i]='*';
            }
        }
    }
    int ans=0;
    int hash[3005]={0};
    for(i=0;i<n;i++)
    {
        int cnt=0;
        for(j=0;j<len;j++)
        {
            if(s[j]!=a[i][j])
            {
                cnt++;
            }
        }
        if(cnt==0)
            ans++;
        else if(cnt==1)
        {
            for(j=0;j<len;j++)
            {
                if(s[j]!=a[i][j])
                {
                    hash[j]++;
                }
            }
        }
    }
    int ans1=0;
    for(i=0;i<3001;i++)
    {
        ans1=max(ans1,hash[i]);
    }
    ans=ans+ans1;
    cout<<ans<<"\n";
	return 0;
}
