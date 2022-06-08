#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,c=0;
  for(int i=0;i<3;i++)for(int j=0;j<3;++j)cin>>a,c+=a;
  if(c%3==0)cout<<"Yes";
  else cout<<"No";
}