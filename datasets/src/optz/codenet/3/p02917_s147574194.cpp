#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
vector <int> b(n-1);
for(int i=0;i<n-1;i++)
  {
    cin>>b[i];
  }
  vector <int> a(n,0);
  a[0]=b[0];
  a[1]=b[0];
  for(int i=1;i<n-2;i++)
    {
      if(a[i]==b[i])
      a[i+1]=a[i];
      if(b[i+1]<b[i])
       a[i+1]=b[i+1];
       else if(b[i+1]>b[i])
       {
         a[i+1]=b[i];
         a[i+2]=b[i+1];
       }
       else if(b[i+1]==b[i])
       {
         a[i]=b[i];
         a[i+1]=b[i];
         a[i+2]=b[i];
       }
       }
       a[n-1]=b[n-2];
       for(int i=0;i<n;i++)
        {
          cout<<a[i]<<" ";
        }
}
