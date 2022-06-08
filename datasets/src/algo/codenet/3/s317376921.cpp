#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int a[100010],b[100010],c[100010];
int main()
{
    int n,i,j,sum=0;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
        scanf("%d",&a[i]);
    for(i=0; i<n; ++i)
        scanf("%d",&b[i]);
    for(i=0; i<n; ++i)
        scanf("%d",&c[i]);
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        for(i=0;i<n;++i)
        {int ans;
            int l=0,r=n-1,mid;
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
        printf("%d\n",sum);
    return 0;
}