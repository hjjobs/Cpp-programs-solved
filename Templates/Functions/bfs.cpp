#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector <int> v[10] ;   
int level[10];
bool vis[10];
void bfs(int s) 
{
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;
    vis[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        cout<<p<<" ";
        q.pop();
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
                level[ v[ p ][ i ] ] = level[ p ]+1;                 
                q.push(v[ p ][ i ]);
                vis[ v[ p ][ i ] ] = true;
            }
        }
    }
    
}
int main()
{
    v[1].push_back(2);v[1].push_back(3);
    v[2].push_back(1);v[2].push_back(4);v[2].push_back(5);
    v[3].push_back(1);v[3].push_back(5);v[3].push_back(6);
    v[4].push_back(2);
    v[5].push_back(2);v[5].push_back(3);
    v[6].push_back(3);
    bfs(3);
    cout<<endl;
    for(int i=1;i<7;i++)
        cout<<level[i]<<"\n";
    return 0;
}
