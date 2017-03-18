#include <bits/stdc++.h>
using namespace std;
unsigned long int catalan(unsigned int n)
{
    if (n <= 1) return 1;

    unsigned long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);

    return res;
}

// Driver program to test above function
int main()
{
    int n;
    cin>>n;
    cout<<catalan(n)<<" ";
    return 0;
}