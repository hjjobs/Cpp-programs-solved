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
     #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
      ios::sync_with_stdio(false);cin.tie(0);
        int n;
        while(true)
        {
	        fflush(stdout);
	        printf("1\n");
	        printf("3 1 1 2\n");
	        printf("3 3 3 4\n");
	        fflush(stdout);
	        scanf("%d",&n);
	        if(n==0)
	        {
	        	printf("2\n");
	    		printf("5\n");
	    		fflush(stdout);
	        	break;
	        }
	        else if(n==2)
	        {
	        	printf("2\n");
	    		printf("1\n");
	    		fflush(stdout);
	        	break;
	        }
	        else if(n==1)
	        {
	        	printf("2\n");
	    		printf("2\n");
	    		fflush(stdout);
	        	break;
	        }
	        else if(n==-2)
	        {
	        	printf("2\n");
	    		printf("3\n");
	    		fflush(stdout);
	        	break;
	        }
	        else if(n==-1)
	        {
	        	printf("2\n");
	    		printf("4\n");
	    		fflush(stdout);
	        	break;
	        }
		    fflush(stdout);
        }
        return 0;
}