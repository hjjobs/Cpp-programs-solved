#include<bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++) 
#define loop1(i,n) for(int i=1;i<=n;i++) 
#define ll long long int
#define ini(n,v) memset(n,v,sizeof(n))
#define F first 
#define S second 
#define mp make_pair
#define pb push_back
#define pid pair<int,double>
#define pii pair<int,int> 
#define p_q priority_queue
#define MOD 1000000007
using namespace std;
int i,j,k;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		if(s.length()==1 && s[0]=='1')
		{
			cout<<"1\n1\n";
			continue;
		}
		int size[s.length()],maxi=0;
		int padding=0,pad[s.length()];
		if(s[0]!='1')
		{
			padding=s.length();
			//maxi=s.length()*10+(s[0]-'0');
		}
		else
		{
			padding=s.length()-1;
			//maxi=s.length()*10;
		}
		int total=0;
		loop(i,s.length())
		{
			int place=(s.length()-i-1);
			if(s[i]=='1' )
			{
				pad[i]=(padding-place);
				size[i]=pad[i];
				
			}
			else if(s[i]=='0')
			{
				pad[i]=0;
				size[i]=0;
			}
			else
			{
				pad[i]=(padding-place-1);
				size[i]=(s[i]-'0')+pad[i];
			}
			total=total+size[i];
			//cout<<size[i]<<" "<<pad[i]<<" "<<place<<"\n";
		}
		int lis[10000];
		int l=0;
		int large=total;
		cout<<total+10*(s.length()-1)<<"\n";
		//cout<<total<<"\n";
		int pointer=total;int co=0;
		loop(i,s.length())
		{
			int place=(s.length()-i-1);
				int numb,lol=0;
				if(place!=0)
				lol=10;
			//cout<<"\nfor "<<i<<" place=>\n";
			if(s[i]!='0')
			{	
				
				numb=pointer+1-size[i];
				loop1(j,pad[i])
				{
					lis[l++]=numb;
					cout<<numb++<<" ";
					
					co++;
				}
				numb=pointer;
				if(s[i]!='1')
				{
					
					loop1(k,(s[i]-'0'))
					{
						lis[l++]=numb;
						cout<<numb--<<" ";
						co++;
					}
				}
			}
			if(place!=0)
			{	
				numb=large;
				large=large+10;
				loop1(k,10)
				{
					lis[l++]=large;
					
					cout<<large--<<" ";
					co++;
				}
				large=numb+10;
			}
			pointer=pointer-size[i];	
		}
		cout<<"\n";
	}
	return 0;
} 
