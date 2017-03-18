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
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,te;
		cin>>n;
		int c[105];
		int sum[105]={0};
		for(i=1;i<=n;i++)
		{
			int hash[8]={0};
			int sum1=0;
			cin>>c[i];
			sum1+=c[i];
			for(j=0;j<c[i];j++)
			{
				cin>>te;
				hash[te]++;
			}
			int cnt=0;
			for(j=1;j<=6;j++)
			{
				if(hash[j]>0)
				{
					cnt++;
				}
			}

			if(cnt==4)
				{
				    int x=INT_MAX;
                    for(j=1;j<=6;j++)
			           {
				           if(hash[j]>0)
                        {
					     x=min(x,hash[j]);
				         }
                       }
                       sum1=sum1+x;
				}
			else if(cnt==5)
				{
				    vector<int> v1;
				    vector<int> v2;
				    int ans1=sum1;
				     for(j=1;j<=6;j++)
			           {
				           if(hash[j]>0)
					     v1.push_back(hash[j]);
                       }
                       sort(v1.begin(),v1.end());
                       int k=v1[0];
                       ans1=ans1+(2*k);
                       for(j=1;j<5;j++)
                       {
                           v1[j]=v1[j]-k;
                           if(v1[j]>0)
                            v2.push_back(v1[j]);
                       }
                     sort(v2.begin(),v2.end());
                     if(v2.size()==4)
                        ans1=ans1+v2[0];
                       sum1=ans1;
				}
			else if(cnt==6)
				{
				    int ans1=sum1;
				    vector<int> v1;
				    vector<int> v2;
				    vector<int> v3;
				    for(j=1;j<=6;j++)
			           {
				           if(hash[j]>0)
					     v1.push_back(hash[j]);
                       }
                       sort(v1.begin(),v1.end());
                       int k=v1[0];
                       ans1=ans1+(4*k);
                       for(j=1;j<v1.size();j++)
                       {
                           v1[j]=v1[j]-k;
                           if(v1[j]>0)
                            v2.push_back(v1[j]);
                       }
                     sort(v2.begin(),v2.end());
                      if(v2.size()==4)
                        ans1=ans1+v2[0];
                        else if(v2.size()==5)
                        {
                            ans1=ans1+(2*v2[0]);
                            k=v2[0];
                             for(j=1;j<v2.size();j++)
                        {
                           v2[j]=v2[j]-k;
                           if(v2[j]>0)
                            v3.push_back(v2[j]);
                        }
                            sort(v3.begin(),v3.end());
                            if(v3.size()==4)
                                ans1=ans1+v3[0];
                        }
				    sum1=ans1;

				}

			sum[i]=sum1;
			//cout<<sum[i]<<"\n";
		}
		int maxi=INT_MIN;
		int m;
		int flag=0;
		for(i=1;i<=n;i++)
		{
			if(sum[i]>maxi)
			{
				m=i;
				maxi=sum[i];
			}
		}
		int ct=0;
		for(i=1;i<=n;i++)
		{
			if(sum[i]==maxi)
				ct++;
		}
		if(ct>=2)
		{
			flag=1;
		}
		if(flag==1)
		{
			cout<<"tie\n";
		}
		else
		{
			if(m==1)
			{
				cout<<"chef\n";
			}
			else
			{
				cout<<m<<"\n";
			}
		}
	}
	return 0;
}