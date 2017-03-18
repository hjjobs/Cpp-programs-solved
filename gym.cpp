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
		string a,b;
		int i;
		int hash1[10]={0};
		int hash2[10]={0};
		int hash3[10]={0};
		int hash4[10]={0};
		int flag=0;
		cin>>a>>b;
		for(i=0;i<a.length();i++)
		{
			hash1[a[i]-'0']++;
			hash3[a[i]-'0']++;

		}
		for(i=0;i<b.length();i++)
		{
			hash2[b[i]-'0']++;
			hash4[b[i]-'0']++;
		}
		for(i=0;i<10;i++)
		{
			if((hash1[i]==0&&hash2[i]!=0)||(hash1[i]!=0&&hash2[i]==0))
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"friends\n";
		}
		else
		{
			int k=0;
			flag=0;
			int lol=0;
			int hj=0;
			int j;
			for(j=0;j<a.length()-1;j++)
			{
				int x=a[j]-'0';
				int y=a[j+1]-'0';
				if(x+1>=0&&x+1<=9&&y-1>=0&&y-1<=9)
				{
					flag=0;
					hash3[x]--;
				    hash3[y]--;
				    hash3[x+1]++;
				    hash3[y-1]++;
                   for(i=0;i<10;i++)
		            {
			          if((hash3[i]==0&&hash2[i]!=0)||(hash3[i]!=0&&hash2[i]==0))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
                     cout<<"almost friends"<<"\n";
                     //cout<<1<<"\n";
                     lol=1;
                     hj=1;
                     break;
					}
					for(i=0;i<10;i++)
		            {
		            	hash3[i]=hash1[i];
					}  
				}
				if(x-1>=1 && x-1<=9 && y+1>=0 && y+1<=9 && i==0)
				{
					flag=0;
					hash3[x]--;
				    hash3[y]--;
				    hash3[x-1]++;
				    hash3[y+1]++;
 					for(i=0;i<10;i++)
		            {
			          if((hash3[i]==0&&hash2[i]!=0)||(hash3[i]!=0&&hash2[i]==0))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						lol=1;
                         //cout<<"3"<<"\n";
						cout<<"almost friends"<<"\n";
						hj=1;
						break;
					}
					for(i=0;i<10;i++)
		            {
		            	hash3[i]=hash1[i];
					}
				}
				else if(x-1>=0 && x-1<=9 && y+1>=0 && y+1<=9 && j!=0)
				{
					flag=0;

					hash3[x]--;
				    hash3[y]--;
				    hash3[x-1]++;
				    hash3[y+1]++;
					for(i=0;i<10;i++)
		            {
			          if((hash3[i]==0&&hash2[i]!=0)||(hash3[i]!=0&&hash2[i]==0))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						cout<<"almost friends"<<"\n";
						lol=1;
                        //cout<<2<<"\n";
                        //cout<<x<<" "<<y<<"\n";
                        hj=1;
                        break;
						//continue ;
					}
					for(i=0;i<10;i++)
		            {
		            	hash3[i]=hash1[i];
					} 
				}
				
			}
			if(hj==1)
			{
			   continue;
			}
			for(j=0;j<b.length()-1;j++)
			{
				int x=b[j]-'0';
				int y=b[j+1]-'0';
				if(x+1>=0&&x+1<=9&&y-1>=0&&y-1<=9)
				{
					flag=0;
					hash4[x]--;
				    hash4[y]--;
				    hash4[x+1]++;
				    hash4[y-1]++;
                   for(i=0;i<10;i++)
		            {
			          if((hash1[i]==0&&hash4[i]!=0)||(hash1[i]!=0&&hash4[i]==0))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
                     cout<<"almost friends"<<"\n";
                     lol=1;
                        // cout<<"4"<<"\n";                 
                     hj=1;
                     break;
					}
					for(i=0;i<10;i++)
		            {
		            	hash4[i]=hash2[i];
					}  
				}
				if(x-1>=0 && x-1<=9 && y+1>=0&&y+1<=9 && j!=0)
				{
					flag=0;
					hash4[x]--;
				    hash4[y]--;
				    hash4[x-1]++;
				    hash4[y+1]++;
					for(i=0;i<10;i++)
		            {
			          if((hash4[i]==0&&hash1[i]!=0)||(hash4[i]!=0&&hash1[i]==0))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						lol=1;

						cout<<"almost friends"<<"\n";
						//cout<<"5"<<"\n";
						hj=1;
						break;
					}
					for(i=0;i<10;i++)
		            {
		            	hash4[i]=hash2[i];
					} 
				}
				else if(x-1>=1 && x-1<=9 && y+1>=0&&y+1<=9 && j==0)
				{
					flag=0;
					hash4[x]--;
				    hash4[y]--;
				    hash4[x-1]++;
				    hash4[y+1]++;
 					for(i=0;i<10;i++)
		            {
			          if((hash4[i]==0&&hash1[i]!=0)||(hash4[i]!=0&&hash1[i]==0))
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						lol=1;

						cout<<"almost friends"<<"\n";
						hj=1;
						break;
					}
					for(i=0;i<10;i++)
		            {
		            	hash4[i]=hash2[i];
					}
				}
			}
			if(hj==1)
			{
              continue;
			}
             if(lol==0)
             	cout<<"nothing"<<"\n";



		}
	}
	return 0;
}
