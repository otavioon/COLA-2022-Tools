#include<bits/stdc++.h> 
using namespace std; 
const int s=1e5+2; 
int a[s],b[s],c[s]; 
int main() 
{ 
int n,k,j,ans=0,i; 
scanf("%d",&n); 
for(i=1;i<=n;++i) 
scanf("%d",&a[i]); 
for(i=1;i<=n;++i) 
scanf("%d",&b[i]); 
for(i=1;i<=n;++i) 
scanf("%d",&c[i]); 
sort(a+1,a+1+n);
sort(b+1,b+1+n);
sort(c+1,c+1+n); 
for(i=1;i<=n;++i) 
{ j=1; 
while(a[j]<b[i]&&j<=n)j++; 
j--; k=n; 
while(b[i]<c[k]&&k>=1)k--; k++; 

int s=n-k+1; ans+=s*j; } 
printf("%d",ans); 
return 0; }