#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  int x[t+2],y[t+2],z[t+2];
    for(int j=0;j<t;j++)
    {
      cin>>x[j];
    }
    sort(x,x+t);
    for(int j=0;j<t;j++)
    {
      cin>>y[j];
    }
    sort(y,y+t);
    for(int j=0;j<t;j++)
    {
      cin>>z[j];
    }
    sort(z,z+t);
  int c=0;
  bool e=1;
  for(int i=0;i<t && e;i++)
  {
    for(int j=0;j<t;j++)
    {
      if(x[i]>=y[j]) {e=0;break;}
      if(x[i]<y[j])
      {
        for(int k=0;k<t;k++) if(y[j]<z[k]) c++; else break;
      }
    }
  }
  cout<<c<<endl;
  return 0;
}