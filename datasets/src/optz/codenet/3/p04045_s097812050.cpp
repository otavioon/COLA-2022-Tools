#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAXN 10010
using namespace std;
int n,m;
bool dont[MAXN],used[MAXN];
int last[MAXN],ans[MAXN];
void print(int next,int ceng)
{
    if(ceng&&!next) return;
    print(last[next],ceng+1);
    printf("%d",ans[next]);
}
int main()
{
    scanf("%d%d",&n,&m);
    bool judge=false;
    memset(dont,false,sizeof(dont));
    memset(used,false,sizeof(used));
    for(int i=1; i<=m; i++)
    {
        int temp;
        scanf("%d",&temp);
        dont[temp]=true;
    }
    queue <int> q;
    while(!q.empty()) q.pop();
    q.push(0);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for (int i=0; i<10; i++)
        {
            if(dont[i]||!now&&!i) continue;
            int mod=(now*10+i)%n;
            if(!used[mod])
            {
                q.push(mod);
                used[mod]=true;
                last[mod]=now;
                ans[mod]=+i;
                if(!mod)
                {
                    judge=true;
                    break;
                }
            }
        }
        if(judge) break;
    }
    if(judge)
    {
        print(0,0);
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
