#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
vector<int> v;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        m.clear();
        string s;
        int k;
        cin>>s>>k;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
            int min1=INT_MAX,max1=INT_MIN;
            for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
            {
                min1=min(min1,it->second);
                max1=max(max1,it->second);
                v.push_back(it->second);
             }
            long long ans=LONG_LONG_MAX;
               for(int j=min1;j<=max1;j++)
               {
                long long sum=0;
                   for(int i=0;i<v.size();i++)
                   {
                   if(v[i]<j)
                        sum+=v[i];
                   if(v[i]>j+k)
                    sum+=v[i]-(j+k);
                   }
                   ans=min(sum,ans);
               }
            printf("%lld\n",ans);
    }
    return 0;
}