#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100010],b[100010],c[100010],n,i,j,k,m;
void fun()
{
    m=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                if(a[i]<b[j]&&b[j]<c[k])
                    m++;

}
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
            scanf("%d",&b[i]);
        for(i=0; i<n; i++)
            scanf("%d",&c[i]);
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        fun();
        printf("%d\n",m);
    }
    return 0;
}