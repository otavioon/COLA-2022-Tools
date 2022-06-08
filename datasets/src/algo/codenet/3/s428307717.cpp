#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxx 1000010
long long l1,r1,l2,r2,num,mid;
long long a[maxx],b[maxx],c[maxx];
int main()
{
    long long t;
    while(~scanf("%lld",&t))
    {
        num=0;
        for(long long i=0; i<t; i++)
            scanf("%lld",&a[i]);
        for(long long i=0; i<t; i++)
            scanf("%lld",&b[i]);
        for(long long i=0; i<t; i++)
            scanf("%lld",&c[i]);
        sort(a,a+t);
        sort(b,b+t);
        sort(c,c+t);
        for(long long i=0; i<t; i++)
        {
            l1=0;
            r1=t-1;
            while(l1<=r1)
            {
                mid=l1+(r1-l1)/2;
                if(a[mid]<b[i])
                    l1=mid+1;
                else
                    r1=mid-1;
            }
            l2=0;
            r2=t-1;
            while(l2<=r2)
            {
                mid=l2+(r2-l2)/2;
                if(c[mid]<=b[i])
                    l2=mid+1;
                else
                    r2=mid-1;
            }
            num=num+(l1*(t-l2));
        }
        printf("%lld\n",num);
    }
    return 0;
}
