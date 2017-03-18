#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<lint,lint>
#define m_p make_pair(n,m)
#define mod 1000000007
#define pb push_back
#define bp(x) __builtin_popcount(x)
#define rep(i, a, b) for (long long int i = (a); i <= (b); ++i)
#define red(i, a, b) for (long long int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long int lint;
const lint maxn = 50001;
lint sum , n , m , a[maxn] , b[maxn] , last[maxn];
std :: set < lint > st[150020];  
std :: set < lint > :: iterator it;
std :: map < lint , lint > h;
 
struct BitTree
{
	struct node {
		lint l , r;
        lint v;
	} T[150020*65];
	lint sz , root[maxn] , Rt[maxn];
	void build(lint &i,lint l,lint r,lint x,lint v) 
	{
	   T[++sz] = T[i]; i = sz;
	   T[i].v += v;
	   lint m = ( l + r ) >> 1;
	   if ( l == r ) return;
	   if ( x <= m ) build( T[i].l , l , m , x , v ); else build( T[i].r , m + 1 , r , x , v );
	}
	void ins(lint &i,lint l,lint r,lint &x,lint &v) 
	{
		if ( !i ) T[++sz] = T[i] , i = sz;
		T[i].v += v;
		if ( l == r ) return;
		lint m = ( l + r ) >> 1;
		if ( x <= m ) ins( T[i].l , l , m , x , v ); else ins( T[i].r , m + 1 , r , x , v );
	}
	void BITins(lint t,lint x,lint v) 
	{
		for ( ; t <= maxn; t += t & -t ) ins( root[t] , 1 , maxn , x , v );
	}
    lint find(lint t,lint L,lint l,lint r) 
    {
        if ( !t || l >= L ) return T[t].v;
        lint m = ( l + r ) >> 1;
        lint sum = find( T[t].r , L , m + 1 , r );
        if ( L <= m ) sum += find( T[t].l , L , l , m );
        return sum;
	}
	lint ask(lint t,lint L) 
	{
        lint ans = find( Rt[t] , L , 1 , maxn );
		for ( ; t; t -= t & -t ) ans += find( root[t] , L , 1 , maxn );
		return ans;
	}
	void init() 
	{
        lint x;
		sz = 0;
		rep(i,1,n) {
            x = Rt[i-1];
            if ( last[a[i]] ) build( x , 1 , maxn , last[a[i]] , -b[i] );
            build( Rt[i] = x , 1 , maxn , i , b[i] );
            last[a[i]] = i;
            st[a[i]].insert( i );
        }
	}
} T;
lint id(lint y)
{
    if ( h.count( y ) ) return h[y];
    h[y] = ++ sum;
    st[sum].insert( 0 );
    st[sum].insert( n + 1 );
    return sum;
} 
void init()
{
    sum = 0;
    cin>>n;
    rep(i,1,n) cin>>b[i] , a[i] = id( b[i] );
    T.init();
    cin>>m;
}
void work()
{
    lint x , y , p , pre , nex;
    while ( m -- ) 
    {
        cin>>x>>y;
        cout<<T.ask( y , x )<<"\n";
    }
}
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	lint t;
	cin>>t;
	while(t--)
	{
	    init();
	    work();
	}
    return 0;
}