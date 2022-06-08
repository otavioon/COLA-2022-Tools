#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[100005],b[100005],c[100005],ans=0,n,nowa,nowc;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) scanf("%d",&c[i]);
    sort(a,a+n);sort(b,b+n);sort(c,c+n);
    nowa=0;nowc=0;
    for (int i=0;i<n;i++)
        {
            while ((a[nowa]<b[i])&&(nowa<n)) nowa++;
            while ((c[nowc]<=b[i])&&(nowc<n)) nowc++;
            ans=ans+nowa*(n-nowc);
        }
    printf("%d",ans);
    return 0;
}
