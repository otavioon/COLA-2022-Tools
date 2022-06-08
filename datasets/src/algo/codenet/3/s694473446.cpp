#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 100010
int a[N],b[N],c[N];
int main()
{
    int i,j,k,n,l,r,mid,p1,p2;
    long long s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    scanf("%d",&c[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    s=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]<=a[1])
        continue;
        if(b[i]>=c[n])
        continue;
        p1=1;
        l=1;
        r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(a[mid]<b[i])
            {
                p1=max(p1,mid);
                l=mid+1;
            }
            else
            r=mid-1;
        }
        p2=n;
        l=1;
        r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(c[mid]>b[i])
            {
                p2=min(p2,mid);
                r=mid-1;
            }
            else
            l=mid+1;
        }
        s=s+(long long)p1*(n-p2+1);
    }
    printf("%lld\n",s);
    return 0;
}