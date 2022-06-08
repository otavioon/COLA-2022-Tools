#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
 
using namespace std;
long long Pow[45];
long long all[200005];
struct A
{
    long long how;
    long long con;
}num[200005];
bool F(long long a,long long b)
{
    return a>b;
}
int main()
{
    long long N,i,j,now=0,ans=0,l,r,t;
    Pow[0]=1;
    for(i=1;i<=35;i++) Pow[i]=Pow[i-1]*2;
    scanf("%lld",&N);
    for(i=0;i<N;i++) scanf("%lld",&all[i]);
    sort(all,all+N,F);
    num[now].how=all[0];
    num[now].con=1;
    /*for(i=0;i<N;i++) printf("%lld ",all[i]);
	printf("\n"); */
    for(i=1;i<N;i++)
    {
        if(all[i]==all[i-1]) num[now].con++;
        else
        {
            now++;
            num[now].how=all[i];
            num[now].con=1;
        }
    }
    for(i=0;i<=now;i++)
    {
        for(j=35;j>=0;j--)
        {
            if(Pow[j]-num[i].how<=0) continue;
            if(Pow[j]-num[i].how==num[i].how)
            {
                ans+=num[i].con/2;
                num[i].con%=2;
            }
            else
            {
                l=i;
                r=now;
                while((r-l)>1)
                {
                    if(num[(r+l)/2].how>=Pow[j]-num[i].how) l=(r+l)/2;
                    else r=(r+l)/2;
                }
                if(num[l].how+num[i].how==Pow[j])
                {
                    t=min(num[l].con,num[i].con);
                    num[l].con-=t;
                    num[i].con-=t;
                    ans+=t;
                }
                else if(num[r].how+num[i].how==Pow[j])
                {
                    t=min(num[r].con,num[i].con);
                    num[r].con-=t;
                    num[i].con-=t;
                    ans+=t;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}