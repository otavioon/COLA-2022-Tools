#include<stdio.h>
#include<algorithm>
int a[100010];
int b[100010];
int c[100010];
long long i,temp,n,q,p;
using namespace std;
long long f(long long e,int a[],long long r,long long l)
{
    while(l>=r)
    {
        temp=r+(l-r)/2;
        if(a[temp]<e)
           r=temp+1;
        if(a[temp]>=e)
             l=temp-1;
    }
    return r;
}
long long F(long long  e,int c[],long long  r,long long l)
{
    while(l>=r)
    {
        temp=r+(l-r)/2;
        if(c[temp]<=e)
           r=temp+1;
        if(c[temp]>e)
             l=temp-1;
    }
    return l+1;
}
int main()
{
    while(~scanf("%lld",&n))
    {
       long long  sum=0;
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        for(i=0; i<n; i++)
            scanf("%lld",&b[i]);
        for(i=0; i<n; i++)
            scanf("%lld",&c[i]);
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        for(i=0; i<n; i++)
        {
            long long  e=b[i];
            q=f(e,a,0,n-1);
            p=F(e,c,0,n-1);
            p=n-p;
            sum=sum+q*p;
        }
        printf("%lld\n",sum);
    }
    return 0;
}