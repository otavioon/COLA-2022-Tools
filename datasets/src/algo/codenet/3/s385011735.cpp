#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 100010
int a[N],b[N],c[N];
long long s[N],t[N];
int main()
{
    int n,i,j,k,p1,p2,flag;
    long long ans=0,s1,s2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    scanf("%d",&c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    p1=n;
    p2=n;
    s1=0;
    for(i=n;i>=1;i--)
    {
        while(b[p1]>a[i]&&p1>=1)
        {
            s1=s[p1+1]+(n-p2);
            while(c[p2]>b[p1]&&p2>=1)
            {
                s1++;
                t[p2]=s1;
                p2--;
            }
            s[p1]=s1;
            p1--;
        }
        ans=ans+s1;
    }
    printf("%lld\n",ans);
    return 0;
}
