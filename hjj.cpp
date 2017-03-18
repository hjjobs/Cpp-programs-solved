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
int arr[105][105];
void lcs(string s1, string s2) {
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] =max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
}
set <string> lcs(string s1, string s2, int len1, int len2) 
{
    if (len1 == 0 || len2 == 0) 
    {
        set <string> st;
        st.insert("");
        return st;
    }
    if (s1[len1 - 1] == s2[len2 - 1]) 
    {
        set <string> st = lcs(s1, s2, len1 - 1, len2 - 1);
        set <string> st1;
        for(set<string> ::iterator it=st.begin();it!=st.end();it++)
        {
            string lol=*it;
            lol=lol+s1[len1-1];
            st1.insert(lol);
        }
        return st1;
    } 
    else 
    {
        set <string> st ;
        set <string> st1;
        if (arr[len1 - 1][len2] >= arr[len1][len2 - 1]) 
        {
            st = lcs(s1, s2, len1 - 1, len2);
        }
        if (arr[len1][len2 - 1] >= arr[len1 - 1][len2]) 
        {
            st1 = lcs(s1, s2, len1, len2 - 1);
        }
        for(set<string> ::iterator it=st.begin();it!=st.end();it++)
        {
            st1.insert(*it);
        }
        return st1;
 
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    string a,b,c;
    cin>>a>>b>>c;
    lcs(a,b);
    set <string> temp;
    int flag=0;
    temp=lcs(a, b, a.length(), b.length());
    for(set<string> ::iterator it=temp.begin();it!=temp.end();it++)
    {
        string man=*it;
        if (man.find(c) == std::string::npos)
        {
            flag=1;
            cout<<man<<"\n";
            break;
        }
    }
    vector <pair <int ,string> > pp;
   if(flag==0)
   {
    for(set<string> ::iterator it=temp.begin();it!=temp.end();it++)
    {
        string man=*it;
        while(man.find(c) != std::string::npos)
        {
            man.erase(man.find(c),c.length());
        }
        
        pp.push_back(make_pair(man.length(),man));
    }
    int l1=0;
    string tt1;
    for(int i=0;i<pp.size();i++)
    {
        if(l1<pp[i].first)
        {
            l1=pp[i].first;
            tt1=pp[i].second;
        }
    }
    if(l1==0)
    {
        cout<<0;
    }
    else
    {
        cout<<tt1;
    }
   }
    return 0;
}