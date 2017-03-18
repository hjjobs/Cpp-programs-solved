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
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,i;
        cin>>n;
        int w[105];
        for(i=1;i<=n;i++)
        {
            cin>>w[i];
        }
        sort(w+1,w+n+1);
        int l=1;
        int r=n;
        int c=0;
        int d=0;
        while(l<r)
        {
            int x=50/w[r];
            if(50%w[r]!=0)
            {
                x++;
            }
            //cout<<x<<"\n";
            int temp=l+x-1;
            if((r-temp)*w[r]>=50)
            {
                c++;
                r--;
                l=l+x-1;
                d=d+x;
            }
            else
            {
                break;
            }
            //cout<<l<<" "<<r<<" "<<c<<" "<<d<<"\n";
        }
        if(d<n)
        {
            c++;
        }
        cout<<"Case #"<<z<<": ";
        cout<<c<<"\n";
    }
	return 0;
}