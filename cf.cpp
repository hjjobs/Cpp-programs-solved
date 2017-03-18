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
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
	int sum = 0; // Iniialize result

	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse ancestors of BITree[index]
	int cnt=0;
	while (index>0)
	{
		// Add current element of BITree to sum
		sum += BITree[index];

		// Move index to parent node in getSum View
		index -= index & (-index);
		cnt++;
	}
	return cnt;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse all ancestors and add 'val'
	while (index <= n)
	{
	// Add 'val' to current node of BI Tree
	BITree[index] += val;

	// Update index to that of parent in update View
	index += index & (-index);
	}
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
	// Create and initialize BITree[] as 0
	int *BITree = new int[n+1];
	for (int i=1; i<=n; i++)
		BITree[i] = 0;

	// Store the actual values in BITree[] using update()
	for (int i=0; i<n; i++)
		updateBIT(BITree, n, i, arr[i]);

	// Uncomment below lines to see contents of BITree[]
	//for (int i=1; i<=n; i++)
	//	 cout << BITree[i] << " ";

	return BITree;
}


// Driver program to test above functions
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		int n;
		cin>>n;
	int freq[10000];// = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i=0;i<n;i++)
	{
		cin>>freq[i];
	}
	//int n = sizeof(freq)/sizeof(freq[0]);
	int *BITree = constructBITree(freq, n);
	for (int i = 1; i < 40; ++i)
	{
		cout<<i<<" "<<getSum(BITree, i)<<"\n";
	}
	//cout<<getSum(BITree, i)<<"\n";
	return 0;
}
