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
#define M_S 1000
int comp(const void* a,const void *b){
        int *A=(*(int**)a);
        int *B=(*(int**)b);
        if(A[0]!=B[0])return A[0]-B[0];
        return A[1]-B[1];
}
int **arr;
int arr2[100005];
int n,m;
int pree[110][100005];
int deg[110]={0};
int main()
{
        #ifndef ONLINE_JUDGE
                freopen("input.txt","r",stdin);
                freopen("output.txt","w",stdout);
        #endif
        ios::sync_with_stdio(false);cin.tie(0);
        int i,j,ai,bi,ci,di,k,t;
        ll li,ri;
        int a1[100005]={0};
        cin>>n>>m;
        arr=new int*[n+1];
        for(int i=1;i<=n;i++){
                arr[i]=new int[2];
                cin>>arr[i][0];
                a1[i]=arr[i][0];
                arr[i][1]=i;
                arr2[i]=arr[i][0];
        }
        qsort(arr+1,n,sizeof(int),comp);    
        for(int i=0;i<110;i++){
                for(int e=0;e<100005;e++){
                        pree[i][e]=0;
                }
        }
        for(int i=1;i<=n;i++){
                pree[(i-1)/M_S][arr[i][1]]=1;
        }
        for(int i=0;i<110;i++){
                for(int e=1;e<=n;e++){
                        pree[i][e]+=pree[i][e-1];
                }
        }
        int a,b,tmp;
        int ans=0;
        for(i=1;i<=m;i++)
        {
                set <int> temp;
                cin>>ai>>bi>>ci>>di>>k;
                if(k>1)
                {
                        li=(ai*max(ans,0)+bi)%n+1;
                        ri=(ci*max(ans,0)+di)%n+1;
                        if(li>ri)
                        {
                                t=li;
                                li=ri;
                                ri=t;
                        }
                        for(j=li;j<=ri;j++)
                        {
                                temp.insert(a1[j]);
                        }
                        if(k>temp.size())
                        {
                                cout<<-1<<"\n";
                                ans=-1;
                        }
                        else
                        {
                                std::set<int>::iterator it =temp.begin();
                                std::advance(it,k-1);
                                int x = *it;
                                cout<<x<<"\n";
                                ans=x;
                        }
                }
                else
                {
                        tmp=0;
                        a=(ai*max(ans,0)+bi)%n+1;
                        b=(ci*max(ans,0)+di)%n+1;
                        if(a>b)
                        {
                                t=a;
                                a=b;
                                b=t;
                        }
                        k=1;
                        for(int i=0;i<110;i++)
                        {
                                if(tmp+pree[i][b]-pree[i][a-1]>=k)
                                {
                                        for(int e=i*M_S;e<(i+1)*M_S && e<=n;e++)
                                        {
                                                if(arr[e+1][1]>=a && arr[e+1][1]<=b)
                                                {
                                                        tmp++;
                                                }
                                                if(tmp==k)
                                                {
                                                        cout<<arr2[arr[e+1][1]]<<endl;
                                                        ans=arr2[arr[e+1][1]];
                                                        break;
                                                }
                                        }
                                        break;
                                } 
                                else 
                                {
                                        tmp+=pree[i][b]-pree[i][a-1];
                                }
                        }
                }
        }
        return 0;
}