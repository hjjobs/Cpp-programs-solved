#include <bits/stdc++.h>
using namespace std;
unsigned long long int dp[105];
unsigned long int catalan(unsigned int n)
{
    if(dp[n]!=(-1))
    {
        return dp[n];
    }
    if (n <= 1)
    {
        dp[n]=1;
        return dp[n];
    }
      else
      {
          unsigned long int res = 0;
    for (int i=0; i<n; i++)
       {
          res += catalan(i)*catalan(n-i-1);
       }
        dp[n]=res;
    return dp[n];
      }

}
int main()
{
    int i;
    for(i=0;i<=104;i++)
        dp[i]=-1;
    int n;
    cin>>n;
    cout<<catalan(n)<<" ";
    return 0;
}