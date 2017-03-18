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
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    	#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif
        ll n,i,j,sum=0;
        string a[50005];
        map <ll,int> count;
        cin>>n;
        for(i=0;i<n;i++)
        {
            int vis[17]={0};
            sum=0;
                cin>>a[i];
                for(j=0;j<a[i].length();j++)
                {
                    //cout<<a[i][j]<<" ";
                if(a[i][j]=='0'&&vis[0]==0)
                {   sum=sum+1*pow(2,0);
                    vis[0]++;
                }
                else if(a[i][j]=='1'&&vis[1]==0)
                {   sum=sum+1*pow(2,1);
                    vis[1]++;
                }
                else if(a[i][j]=='2'&&vis[2]==0)
                {   sum=sum+1*pow(2,2);
                    vis[2]++;
                }
                else if(a[i][j]=='3'&&vis[3]==0)
                {   sum=sum+1*pow(2,3);
                    vis[3]++;
                }
                else if(a[i][j]=='4'&&vis[4]==0)
                {   sum=sum+1*pow(2,4);
                    vis[4]++;
                }
                else if(a[i][j]=='5'&&vis[5]==0)
                {   sum=sum+1*pow(2,5);
                    vis[5]++;
                }
                else if(a[i][j]=='6'&&vis[6]==0)
                {   sum=sum+1*pow(2,6);
                    vis[6]++;
                }
                else if(a[i][j]=='7'&&vis[7]==0)
                {   sum=sum+1*pow(2,7);
                    vis[7]++;
                }
                else if(a[i][j]=='8'&&vis[8]==0)
                {   sum=sum+1*pow(2,8);
                    vis[8]++;
                }
                else if(a[i][j]=='9'&&vis[9]==0)
                {   sum=sum+1*pow(2,9);
                    vis[9]++;
                }
                else if(a[i][j]=='A'&&vis[10]==0)
                {   sum=sum+1*pow(2,10);
                    vis[10]++;
                }
                else if(a[i][j]=='B'&&vis[11]==0)
                {   sum=sum+1*pow(2,11);
                    vis[11]++;
                }
                else if(a[i][j]=='C'&&vis[12]==0)
                {   sum=sum+1*pow(2,12);
                    vis[12]++;
                }
                else if(a[i][j]=='D'&&vis[13]==0)
                {   sum=sum+1*pow(2,13);
                    vis[13]++;
                }
                else if(a[i][j]=='E'&&vis[14]==0)
                {   sum=sum+1*pow(2,14);
                    vis[14]++;
                }
                else if(a[i][j]=='F'&&vis[15]==0)
                {   sum=sum+1*pow(2,15);
                    vis[15]++;
                }
            }
            count[sum]++;
        }
        ll result=0;
        for (map<ll,int>::iterator it=count.begin(); it!=count.end(); ++it)
        {
            if(it->second>=3)
            {
                result+=(it->second*(it->second-1)*(it->second-2))/6;
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}