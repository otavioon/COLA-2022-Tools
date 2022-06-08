#include<bits/stdc++.h>
using namespace std;

int main(){
  int c1,c2,c3;
  cin>>c1>>c2>>c3;
  int d1=c2-c1, d2=c3-c2;
  bool OK=true;
  for(int i=0;i<2;i++){
    int a,b,c;cin>>a>>b>>c;
    if(!(d1==b-a && d2==c-b))
      OK=false;
  }
  
  if(OK)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}