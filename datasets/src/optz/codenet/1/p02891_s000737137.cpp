#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  string s;
  ll k,ans,n;
  cin>>s>>k;
  n=s.size();
  vector<int> data;
  int a=1;
  if(n==2){
   if(s[0]==s[1])cout<<k<<endl;
    else cout<<0<<endl;
    return 0;
  }
  rep(i,n-1){
   if(s[i]==s[i+1]) a++;
   else{
    data.emplace_back(a);
    a=1;
   }
  }
  data.emplace_back(a);
  ll m=data.size(),aans=0,bans=0,cans=0,dans=0;
  //rep(i,m)cout<<data[i]<<" ";
  rep(i,m-1)aans += data[i]/2;
  rep(i,m-1){
   if(i==0) bans += (data[0]+data[m-1])/2;
   else bans += data[i]/2;
  }
  cans=bans+data[m-1]/2;
  dans=aans+data[m-1]/2;
    if(m==1){
    cout<<data[0]*k/2<<endl;
    return 0;
  }
  if(s[0]==s[m-1]){
  if(k==1){
   cout<<dans<<endl;
   return 0;
  }
  cout<<aans+(k-2)*bans+cans<<endl;
    return 0;
  }
  cout<<k*dans<<endl;
}
