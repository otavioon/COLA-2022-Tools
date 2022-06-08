#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#define N 100000
int main()
{
 int a[N];
 int b[N];
 int c[N];
 int n,m,M,i,k,sum;
 cin>>n;
 m=0;
 M=0;
 sum=0;
for(i=0;i<n;i++)
 {
     cin>>a[i];
 }
  for(i=0;i<n;i++)
 {
     cin>>b[i];
 } for(i=0;i<n;i++)
 {
     cin>>c[i];
 }
 sort(a,a+n);
 sort(c,c+n);
 for(i=0;i<n;i++)
 {
     for(k=0;k<n;k++)
     {
        if(b[i]>a[k])
        continue;
     else
        break;
     }
     m=k;
     for(k=0;k<n;k++)
     {
        if(b[i]>=c[k])
        continue;
     else
        break;
     }
    M=n-k;
     sum=sum+M*m;
}
     cout<<sum;
}
