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
int isprime[10000005];
void sieve()
{
    for(int i=0;i<=10000002;i++)
        isprime[i]=0;
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i*i<10000002;i++)
    {
        if(!isprime[i])
        {
            isprime[i]=i;
            for(int j=i*i;j<10000002;j=j+i)
            {
                isprime[j]=i;
            }
        }
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    ios::sync_with_stdio(false);cin.tie(0);
    sieve();
	int t;
    cin>>t;
    map <int ,int > mp;
    while(t--)
    {
        int n;
        int mini,k,i,ans=1;
        cin>>n;
        int arr[100005];
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int temp;
        for(i=1;i<=n;i++)
        {
            if(arr[i]!=1)
            {
                temp=arr[i];
                mini=1;
                while(temp!=1)
                {
                    k=isprime[temp];
                    if(!mp.count(k))
                    {
                        if(k==0)
                        {
                            mp[temp]=1;
                            isprime[temp]=temp;
                            temp=1;
                        }
                        else
                        {
                            mp[k]=1;
                            while(temp%k==0)
                                temp/=k;
                        }
                    }
                    else
                    {
                        mini=max(mini,1+mp[k]);
                        while(temp%k==0)
                            temp/=k;
                    }
                }
                while(arr[i]!=1)
                {
                    k=isprime[arr[i]];
                    mp[k]=mini;
                    while(arr[i]%k==0)
                        arr[i]/=k;
                }
                ans=max(ans,mini);
            }
        }
        cout<<ans<<"\n";
        mp.clear();
    }
	return 0;
}
