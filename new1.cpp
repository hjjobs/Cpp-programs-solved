#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
#define m_p make_pair(n,m)
#define mod 1000000007
#define pb push_back
#define bp(x) __builtin_popcnt(x)
typedef long long int ll;
int check(ll a[],ll mid,int n,int c)
{
    int cnt =0,i=1;
    ll l=a[0],r;
    while(i<n)
    {
        if((a[i]-l)<mid)
        {
           i++;
        }
        else if((a[i]-l)<mid&&i==n-1)
        {
          cnt++;
          l=a[n-1];
        }
        else if((a[i]-l)==mid)
        {
            cnt++;
            l=a[i];
        i++;
        }
        else if((a[i]-l)>mid)
        {
            ll temp=a[i-1];
            if(l==temp)
            {
                return 0;
            }
            else
            {
               cnt++;
           l=a[i-1];
            }
 
 
        }
    }
if(cnt<c||(a[n-1]==l&&cnt==c))
{
    return 1;
}
else
{
   return 0;
}
 
}
ll binarysearch(ll a[],int n,int c)
{
ll low=0,high=a[n-1],mid,ans=0;
while(low<=high)
{
mid=(low+high)/2;
//cout<<mid<<"\n";
if(check(a,mid,n,c))
{
high = mid - 1;
            ans = mid;
            //cout<<"lol"<<" "<<
            //ans<<"\n";
}
else
{
low=mid+1;
}
}
return ans;
}
int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
scanf("%d",&t);
while(t--)
{
    int c,n,i;
    scanf("%d %d",&n,&m);
    ll a[100005],value;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    value=binarysearch(a,n,c);
    cout<<value<<"\n";
}
    return 0;
}