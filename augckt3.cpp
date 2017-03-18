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
#define PI acos(-1)
typedef long long int ll;
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}
double x[1000005];
double y[1000005];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	//ios::sync_with_stdio(false);cin.tie(0);
	int n,i,j;
	double d,r;
	cin>>n>>d>>r;
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	double sum=0.0;
	for(i=0;i<n;i++)
	{
		double d1=sqrt(x[i]*x[i]+y[i]*y[i]);
		//cout<<d1<<"\n";
		if(d1+d<=r)
		{
			sum+=(d*d)/(r*r);
			//printf("%.4lf\n", sum);
		}
		else if(d1+r<=d)
			sum+=1.0;
		else
		{
			if(r+d<=d1)
				continue;
			else
			{
				double s1 = (r+d+d1)/2.0;
	    		double area1 = sqrt(s1*(s1-r)*(s1-d)*(s1-d1));
	    		//double s2 = (d+d+dist)/2.0;
	    		//double area2 = sqrt(s2*(s2-d)*(s2-d)*(s2-dist));

	    		double t1=(acos((r*r+d1*d1-d*d)/(2.0*r*d1))*r*r);
	    		double t2=(acos((d*d+d1*d1-r*r)/(2.0*d*d1))*d*d);
	    		double ans=t1+t2-area1-area1;
	    		//printf("%.4lf\n", ans);
	    		sum=sum+(ans/(acos(-1)*r*r));
	    		//printf("%.4lf\n", sum);
			}
		}
	}
	printf("%.4lf\n", sum);
	return 0;
}
