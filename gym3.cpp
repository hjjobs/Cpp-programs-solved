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
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t;
 cin>>t;
 while(t--)
 {
    int n,d,i,j;
    int maxix,maxiy,minix,miniy;
    int y1,x1,y2,x2;
    cin>>d>>n;
    int x[100005];
    int y[100005];
    map < ll,int> mp1;
    map < ll,int> mp2;
    map <int,int> mpx;
    map <int,int> mpy;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        mp1[x[i]]++;
        mp2[y[i]]++;
        mpx[x[i]]=y[i];
        mpy[y[i]]=x[i];
    }
    maxix=x[0];
    minix=x[0];
    maxiy=y[0];
    miniy=y[0];
    for(i=0;i<n;i++)
    {
        if(x[i]>=maxix)
        {
            maxix=x[i];
            y1=y[i];
        }
        if(y[i]>=maxiy)
        {
            maxiy=y[i];
            x1=x[i];
        }
        if(x[i]<=minix)
        {
            minix=x[i];
            y2=y[i];
        }
        if(y[i]<=miniy)
        {
            miniy=y[i];
            //cout<<x[i]<<"\n";
            x2=x[i];
        }
    }
    map <ll,int>::iterator it1;
    map <ll,int>::iterator it2;
    map <int,int> temp;
    for(it1=mp1.begin();it1!=mp1.end();it1++)
    {
    	temp[(it.first)%d]+=it1.second;
    }
    for(it2=mp2begin();it2!=mp2.end();it2++)
    {

    }
    cout<<maxix<<" "<<y1<<"\n";
    cout<<x1<<" "<<maxiy<<"\n";
    cout<<minix<<" "<<y2<<"\n";
    cout<<x2<<" "<<miniy<<"\n";
 }
    return 0;
}