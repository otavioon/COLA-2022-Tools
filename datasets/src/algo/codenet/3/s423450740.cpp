#include <iostream>
using namespace std;
#include<string.h>
#include<set>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <cstdio>
#include <cstdlib>
#include<stack>
#include<vector>
int a[11000];
int b[11000];
int c[11000];
int main()
{
    int n;
    cin>>n;
    int t;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    int add1=1;
    int add2=1;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        while(a[add1]<b[i]&&add1<n)
            add1++;
        while(c[add2]<=b[i]&&add2<n)
            add2++;
        if(a[1]>=b[i]||c[n]<=b[i])
            continue;
        if(a[add1]<b[i])
            sum+=add1*(n-add2+1);
        else
            sum+=(add1-1)*(n-add2+1);
        //cout<<add1<<"_"<<add2<<endl;
        //cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
