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
    int n,m,i,j,q;
    string a1[200005];
    string a2[200005];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a1[i];
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a2[i];
    }
    cin>>q;
    for(int z=0;z<q;z++)
    {
        int val;
        cin>>val;
        if(val==1)
        {
            int ind,pos;
            char a;
            cin>>ind>>pos>>a;
            pos--;
            a2[ind][pos]=a;
        }
        else if(val==2)
        {
            int ind;
            char a;
            cin>>ind;
            cin>>a;
            a2[ind]=a2[ind]+a;
        }
        else
        {
            int ind;
            int c=0;
            cin>>ind;
            for(i=1;i<=n;i++)
            {
                if(a1[i].find(a2[ind])!=std::string::npos)
                    c++;
            }
            cout<<c<<"\n";
        }
    }
	return 0;
}