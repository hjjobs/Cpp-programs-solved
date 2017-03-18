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
bool check(int A , vector<ll> &v , ll mid){
    int  n = v.size() , i = 0 , tot = 1;
    ll count = 0;
    while(i < n)
    {
        if((long long)v[i] > mid)
            return false;
        if(count + (long long )v[i] > mid){
            tot++;
            count = 0;
        }
        if(count <= mid){
            count += (long long)v[i];
            i++;
        }
    }
    if(tot <= A)
        return true;
    return false;
}
bool print(int pos , int k ,vector<ll> &v , ll mid){
    ll count = 0;
    int pos_till = -1;
    for(int i = pos ; i>= 0 ; i--){
        if(count + v[i] > mid || i == k-2){
            print(i , k-1  , v , mid);
            pos_till = i;
            break;
        }
        count += v[i];
    }
    if(pos_till >= 0)
        cout<<pos_till+1<<" ";
    /*for(int i = pos_till +1 ; i<= pos ; i++)
        printf("%d ", v[i]);*/
}
ll binary_search(vector<ll> &v , int A){
    ll low = 1 , high = LLONG_MAX , mid , ans = LLONG_MAX;
    while(low < high){
        mid = (low + high)>>1;
        if(check(A , v , mid)){
            ans = min(ans , mid);
            high = mid;
        } else
            low = mid+1;
    }
    return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,p,i,j;
	cin>>n>>p;
	ll arr[505][505];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	vector < ll > rsum;
	vector < ll > csum;
	for(i=0;i<n;i++)
	{
		ll sum=0;
		for(j=0;j<n;j++)
		{
			sum+=arr[i][j];
		}
		rsum.push_back(sum);
	}
	rsum.push_back(0);
	for(i=0;i<n;i++)
	{
		ll sum=0;
		for(j=0;j<n;j++)
		{
			sum+=arr[j][i];
		}
		csum.push_back(sum);
	}
	csum.push_back(0);
	ll ans = binary_search(rsum , p);
    print(rsum.size() - 2 , p , rsum , ans);
    printf("\n");
    ll ans1 = binary_search(csum , p);
    print(csum.size() - 2 , p , csum , ans1);
    printf("\n");
	return 0;
}
