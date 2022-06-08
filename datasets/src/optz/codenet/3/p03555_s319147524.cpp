#include<bits/stdc++.h>
using namespace std;
int dp[100005];
bool flag[100005];
void bfs(int k);
int main(void)
{
    int n;
    scanf("%d",&n);
    memset(dp,0x3f,sizeof(dp));
    memset(flag,0,sizeof(flag));
    bfs(n);
    printf("%d\n",dp[0]);
    return 0;
}
void bfs(int k)
{
    dp[1] = 1;
    queue<int>que;
    que.push(1);
    flag[1] = true;
    while(!que.empty())
    {
        int id = que.front();
        flag[id] = false;
        que.pop();
        if(dp[(id*10)%k] > dp[id])
        {
            dp[(id*10)%k] = dp[id];
            if(!flag[(id*10)%k])
            {
                flag[(id*10)%k] = true;
                que.push((id*10)%k);
            }
        }
        if(dp[(id + 1)%k] > dp[id] + 1)
        {
            if(!flag[(id + 1)%k])
            {
                flag[(id + 1)%k] = true;
                dp[(id + 1)%k] = dp[id] + 1;
                que.push((id + 1)%k);
            }
        }
    }
}
