#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <math.h>
 
#define ll long long int
#define maxN 100000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL
 
#define gcd(a,b) __gcd(a,b)
 
using namespace std;
 
int n,k;
int a[maxN+5];
bool visit[maxN+5];
int b[maxN+5];
 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t,i,x,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
        {
            a[i] = 0;
            b[i] = 0;
            visit[i] = false;
        }
        if((2*k)>n)
        {
            printf("-1\n");
            continue;
        }
        if(k==0)
        {
            for(i=1;i<=n;i++)
                printf("%d ",i);
            printf("\n");
            continue;
        }
        n-=2*k;
        for(i=1;i<=n;i++)
        {
            x=(i-1)/k;
            if((x%2)==0)
                a[i]=i+k;
            else
                a[i]=i-k;
            visit[a[i]]=true;
        }
        n+=2*k;
        cnt=1;
        for(i=1;i<=n;i++)
        {
            if(!visit[i])
            {
                b[cnt]=i;
                cnt++;
            }
        }
        n-=2*k;
        for(i=1;i<cnt;i++)
        {
            x=(i-1)/k;
            if((x%2)==0)
                a[n+i]=b[i+k];
            else
                a[n+i]=b[i-k];
        }
        n+=(cnt-1);
        for(i=1;i<=n;i++)
        {
            if(i<n)
            	printf("%d ",a[i]);
            else
            	printf("%d",a[i]);
        }
        printf("\n");
    }
}