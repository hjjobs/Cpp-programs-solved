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
	int t,n,m;
	int arr[11][11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 3, 7, 11, 19, 23, 35, 43, 55, 63, 0, 1, 4, 13, 22, 55, 64, 133, 172, 247, 280, 0, 1, 5, 21, 37, 125, 141, 397, 533, 837, 925, 0, 1, 6, 31, 56, 241, 266, 971, 1336, 2221, 2406, 0, 1, 7, 43, 79, 415, 451, 2047, 2863, 4939, 5275, 0, 1, 8, 57, 106, 659, 708, 3865, 5468, 9675, 10228, 0, 1, 9, 73, 137, 985, 1049, 6713, 9577, 17257, 18105, 0, 1, 10, 91, 172, 1405, 1486, 10927, 15688, 28657, 29890, 0, 1, 11, 111, 211, 1931, 2031, 16891, 24371, 44991,46711 };
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<11;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
	return 0;
}
