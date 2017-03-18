#include <iostream>
#include <vector>
using namespace std;
int is[1000005]={0};
void sieve()
{
    int i,j;
for(i=2;i<=1000;i++)
{
	if(is[i]==0)
	{
	for(j=i*i;j<=1000000;j=j+i)
	{
	is[j]=1;
	}
	}
}
}
int main()
{
    int n,i,x;
    sieve();
    cin>>n>>x;
    //vector<int> v;
    vector<int> v1;
    int c=0,j;
    for(i=2;i<=n;i++)
    {
    	if(is[i]==0)
    	{
    		int k=0;
    		int f=0;
    		int temp=i;
    		for(j=1;j<=x&&f==0;j++)
    		{
    			if(is[temp*2+1]==0)
    			{
    				temp=temp*2+1;
    				k++;
    			}
    			else
    			{
    				f=1;
    			}
    		}
    		if(k==x)
    	{
    		v1.push_back(i);
    	}
    	}

    }
    for(i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<"\n";


return 0;
}