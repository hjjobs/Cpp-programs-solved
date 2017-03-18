#include <bits/stdc++.h>
 
using namespace std;

#define ll long long int
int arr[5700000]={0};
int arr2[5700000]={0};
ll arr1[5700000]={0};
int ques=335*300*50;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n,m,q,i,j,k,z,level;
	cin>>n>>m>>q;//scanf
	int d2[n+2][m+2];
	int r1[n+2][m+2];
	int c1[n+2][m+2];
	int a[n+1][m+1];
	int d21[n+2][m+2];
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=m+1;j++)
		{d2[i][j]=0;
		r1[i][j]=0;
		d21[i][j]=0;
		c1[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];//scanf
			d21[i][j]=a[i][j]+d21[i-1][j+1];
			r1[i][j]=a[i][j]+r1[i][j-1];
			c1[i][j]=a[i][j]+c1[i-1][j];
			d2[i][j]=a[i][j]+d2[i-1][j-1];
		}
	}
	int left=0,right=0;
	int s1=0;
	if(!(n == 1 && m == 1))
	{
	for(i=n;i>=1;i--)//bottom to up lefteft to rightight
	{
		for(j=1;j<=m;j++)
		{
			left=i-1;
			right=j+1;
			s1=0;
			while(left>=1&&right<=m)
			{
				if(left==i-1&&right==j+1)
				{
					s1=s1+a[i][j]+a[left][j]+a[i][right];
					if(s1!=0)
					arr[s1]++;
					left--;right++;
				}
				else
				{
					s1=s1+d2[i][right]-d2[left-1][j-1];
					if(s1!=0)
					arr[s1]++;
					left--;right++;
				}
			}
		}
	}
	s1=0;
	for(i=n;i>=1;i--)//bottom to up rightight to lefteft
	{
		for(j=m;j>=1;j--)
		{
			right=i-1;
			left=j-1;
			s1=0;
			while(left>=1&&right>=1)
			{
				if(left==j-1&&right==i-1)
				{
					s1=s1+a[i][j]+a[right][j]+a[i][left];
					if(s1!=0)
					arr[s1]++;
					left--;right--;
				}
				else
				{
					s1=s1+d21[i][left]-d21[right-1][j+1];
					if(s1!=0)
					arr[s1]++;
					left--;right--;
				}
			}
		}
	}
	s1=0;
	for(i=1;i<=n;i++)//up to bottom lefteft to rightight
	{
		for(j=1;j<=m;j++)
		{
			right=i+1;
			left=j+1;
			s1=0;
			while(left<=m&&right<=n)
			{
				if(left==j+1&&right==i+1)
				{
					s1=s1+a[i][j]+a[right][j]+a[i][left];
					if(s1!=0)
					arr[s1]++;
					left++;right++;
				}
				else
				{
					s1=s1+d21[right][j]-d21[i-1][left+1];
					if(s1!=0)
					arr[s1]++;
					left++;right++;
				}
			}
		}
	}
	s1=0;
	for(i=1;i<=n;i++)//up to bottom rightight to lefteft
	{
		for(j=m;j>=1;j--)
		{
			right=j-1;
			left=i+1;
			s1=0;
			while(left<=n&&right>=1)
			{
				if(right==j-1&&left==i+1)
				{
					s1=s1+a[i][j]+a[i][right]+a[left][j];
					if(s1!=0)
					arr[s1]++;
					left++;right--;
				}
				else
				{
					s1=s1+d2[left][j]-d2[i-1][right-1];
					if(s1!=0)
					arr[s1]++;
					left++;right--;
				}
			}
		}
	}
	s1=0;
	for(i=1;i<=n;i++)//up to bottom otheright trightianglefte
	{
		for(j=1;j<=m;j++)
		{
			right=j-1;
			left=j+1;
			s1=0;
			level=1;
			if(right>=1&&left<=m&&i+level<=n)
			s1=s1+a[i][j];
			while(right>=1&&left<=m&&i+level<=n)
			{
				s1=s1+r1[i+level][left]-r1[i+level][right-1];
				level++;
				if(s1!=0)
				arr[s1]++;
				left++;right--;
			}
		}
	}
	s1=0;
	for(i=n;i>=1;i--)//bottom to up otheright trightianglefte
	{
		for(j=1;j<=m;j++)
		{
			left=j-1;
			right=j+1;
			s1=0;
			level=1;
			if(left>=1&&right<=m&&i-level>=1)
			s1=s1+a[i][j];
			while(left>=1&&right<=m&&i-level>=1)
			{
				s1=s1+r1[i-level][right]-r1[i-level][left-1];
				level++;
				if(s1!=0)
				arr[s1]++;
				left--;right++;
			}
		}
	}
	s1=0;
	for(j=1;j<=m;j++)//lefteft to rightight  otheright trightianglefte
	{
		for(i=1;i<=n;i++)
		{
			left=i-1;
			right=i+1;
			s1=0;
			level=1;
			if(left>=1&&right<=n&&j+level<=m)
			s1=s1+a[i][j];
			while(left>=1&&right<=n&&j+level<=m)
			{
				s1=s1+c1[right][j+level]-c1[left-1][j+level];
				level++;
				if(s1!=0)
				arr[s1]++;
				left--;right++;
			}
		}
	}
	s1=0;
	for(j=m;j>=1;j--)//rightight to lefteft otheright trightianglefte
	{
		for(i=1;i<=n;i++)
		{
			right=i-1;
			left=i+1;
			s1=0;
			level=1;
			if(right>=1&&left<=n&&j-level>=1)
			s1=s1+a[i][j];
			while(right>=1&&left<=n&&j-level>=1)
			{
				s1=s1+c1[left][j-level]-c1[right-1][j-level];
				level++;
				if(s1!=0)
				arr[s1]++;
				left++;right--;
			}
		}
	}
	}
	arr1[0]=0;
	arr2[0]=0;
	for(i=1;i<=(335*300*50);i++)
	{
		arr1[i]=arr1[i-1]+(i*arr[i]);
		arr2[i]=arr2[i-1]+arr[i];
	}
	int temp;
	for(i=0;i<q;i++)
	{
		int f=0;
	    cin>>temp;
        int high=upper_bound(arr1,arr1+ques,temp)-arr1;
        if(high==ques)
        {
            cout<<arr2[high];
        }
        else
        {
        	//cout<<high;
        	f=f+arr2[high-1];
        	//cout<<"f="<<f<<" ";
        	temp=temp-arr1[high-1];
        	//cout<<"temp="<<temp<<" ";
        	f=f+temp/high;
            cout<<f;
        }
    	cout<<"\n";
	}
	return 0;
}