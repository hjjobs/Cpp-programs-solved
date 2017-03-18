#include <bits/stdc++.h>

using namespace std;
bool visit[100005];
double n, time[100005], cycle[100005], sum = 0, wait[100005] = {0}, cnt = 0, t, sum1 = 0, tmp[100005];
    cycle[9999] = 100000000.0;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    //cout << "Enter the no of process: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        //cout << "Enter the arrival time : ";
        cin >> time[i];
        //cout << "Enter the CPU cycles : ";
        cin >> cycle[i];
        tmp[i] = cycle[i];
    }
    sum = 0;
    bool flag = 0;
    int prev;
    int j = 0;
    for(double i = time[0] + 1; cnt < n; i++)
    {
        cycle[j]--;
        if(cycle[j] == 0)
        {
            visit[j] = 1;
            cnt++;
            j = 9999;
        }
        prev = j;
        flag = 0;
        for(int k = 0; k < n; k++)
        {
            if(!visit[k] && time[k] <= i)
            {
                if(j == 9999 || cycle[j] > cycle[k])
                {
                    j = k;
                    flag = 1;
                }
            }
        }
        if(flag)
        {
            if(prev != 9999)
            {
                time[prev] = i;
                //i += 0.4;
            }
            wait[j] += (i - time[j]);
        }
    }
    //cout << "Process\tWaiting Time\tTurn around time\n";
    for(int i = 0; i < n; i++)
    {
        t = wait[i] + tmp[i];
        sum1 += t;
        //cout << i + 1 << "\t" << wait[i] << "\t\t" << t << endl;
        sum += wait[i];
    }
    //cout << "Average Waiting Time: " << sum * 1.0 / n << endl;
    cout <<(int)(sum1/n)<< endl;
    return 0;
}
