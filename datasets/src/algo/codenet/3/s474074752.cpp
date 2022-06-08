#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 1000000
//sort(a,a+n);a数组排列,长度n;升序
//sort(a,a+n,greater<int>());int是数组类型;降序
//mid=l+(r-l)/2;避免越界
long long n,i,j,l1,r1,l2,r2,num,a[maxn+10],b[maxn+10],c[maxn+10],mid;
int main()
{
    while(~scanf("%lld",&n))
    {
        num=0;
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
            l1=0;
            r1=n-1;
            while(l1<=r1)
            {
                mid=l1+(r1-l1)/2;
                if(a[mid]<b[i])
                    l1=mid+1;
                else
                    r1=mid-1;
            }
            l2=0;
            r2=n-1;
            while(l2<=r2)
            {
                mid=l2+(r2-l2)/2;
                if(c[mid]<=b[i])
                    l2=mid+1;
                else
                    r2=mid-1;
            }
            num+=l1*(n-l2);
        }
        printf("%lld\n",num);
    }
}
