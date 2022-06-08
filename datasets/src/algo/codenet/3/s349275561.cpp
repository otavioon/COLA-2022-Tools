#include <iostream>
#include <cstdio>
#include<algorithm>

using namespace std;

const int maxx = 100050*3;
//int a[maxx];
long long n;
long long a[3][maxx];
int l,r;
int ok(int mid,long long t, int q)
{
    if(q == 0)
    {
        if(t > a[q][mid])
        {
            return 1;
        }
        else return 0;
    }
    else{
        if(t >= a[q][mid])
        {
            return 1;
        }
        else return 0;
    }
}
int erfen(long long t,int q)
{
    int mid;
    while(l <= r)
    {
        mid = (l+r) / 2;
        if(ok(mid,t,q))
        {
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
//printf("%d-%d\n",q,l);
    return l;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n; j++)
        scanf("%lld",&a[i][j]);
    }
    sort(a[0],a[0]+n);
    sort(a[2],a[2]+n);
 /*   for(int i = 0; i < n; i++)
    {
        printf("%d ",a[0][i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[2][i]);
    }
    printf("\n");*/
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        l = 0,r = n-1;
        int t1 = erfen(a[1][i],0);
        l = 0,r = n-1;
        int t2 = n - erfen(a[1][i],2);
        ans += t1 *t2;
    }
    printf("%lld\n",ans);
    return 0;
}
