#include <bits/stdc++.h>
using namespace std;
//*******************
// Mahmoud Magdy    *
//*******************
#define ll long long
#define endl "\n"

void fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
inline int D()
{
    int m ;
    cin>>m;
    return m ;
}
inline ll lD()
{
    ll m ;
    cin>>m;
    return m ;
}
inline double dD()
{
    double m ;
    cin>>m;
    return m ;
}

int main()
{
    int c=0;
  for(int i=0;i<3;++i)
    for(int j=0;j<3;++j)
  {
      int a=D();
      if(a==0)
        c++;
  }
  if(c>=2)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
