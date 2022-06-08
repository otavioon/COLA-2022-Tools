#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
long long a[100010],b[100010],c[100010];
int main()
{
    long long  n,i,j,sum=0;
    scanf("%lld",&n);
    for(i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    for(i=0; i<n; ++i)
        scanf("%lld",&b[i]);
    for(i=0; i<n; ++i)
        scanf("%lld",&c[i]);
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        for(i=0;i<n;++i)
        {long long ans;
            long long l=0,r=n-1,mid;
            while(r>=l)
            {
                mid=(r+l)/2;
                if(a[mid]>=b[i])
                {
                    r=mid-1;
                }
                else if(a[mid]<b[i])
                {
                    l=mid+1;
                }
            }
            ans=r+1;
            l=0,r=n-1,mid;
            while(r>=l)
            {
                mid=(r+l)/2;
                if(c[mid]>b[i])
                {
                    r=mid-1;
                }
                else if(c[mid]<=b[i])
                {
                    l=mid+1;
                }
            }
            ans*=(n-l);
            sum+=ans;
        }
        printf("%lld\n",sum);
    return 0;
}
