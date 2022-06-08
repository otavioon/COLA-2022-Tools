#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,c=0,i,j,k;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if((a[i]<a[j]+a[k])&&(a[j]<a[i]+a[k])&&(a[k]<a[i]+a[j])) c++;
            }
        }
    }
  cout<<c;
  return 0;
}
