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

int dsu[100100],arr[100100],siz[100100],ord[100100];
long long arr1[100100];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        dsu[i]=i;
        siz[i]=1;
    }
}
int root_find(int x)
{
    while(x!=dsu[x])
    {
        dsu[dsu[x]]=dsu[x];
        x=dsu[x];
    }
    return x;
}
void uni(int x,int y)
{
    x=root_find(x);
    y=root_find(y);
    if(siz[x]>=siz[y])
    {
        siz[x]+=siz[y];
        arr1[x]+=arr1[y];
        dsu[y]=x;
    }
    else
    {
        siz[y]+=siz[x];
        arr1[y]+=arr1[x];
        dsu[x]=y;
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,maxi=0,k;
    stack<int> st;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cin>>ord[i];
    st.push(0);
    init(n);
    for(int i=n-1;i>0;i--)
    {
        arr1[ord[i]]=arr[ord[i]];
        if(ord[i]>1)
            if(arr1[ord[i]-1]!=0)
                uni(ord[i],ord[i]-1);
        if(ord[i]<n)
            if(arr1[ord[i]+1]!=0)
                uni(ord[i],ord[i]+1);
        k=arr1[root_find(ord[i])];
        if(k>maxi)
            maxi=k;
        st.push(maxi);
    }
    while(!st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}