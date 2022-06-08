#include<iostream>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define int64 long long
#define yokuwaruprime (10*10*10*10*10*10*10*10*10+7)
using namespace std;

int main(){
  int a[3],b[3],c[3];
  rep(i,3){
    cin>>a[i]>>b[i]>>c[i];
  }
  int shingi=1;
  rep(i,3){
    if(a[i]+c[i]!=2*b[i]){
      shingi=0;
    }
  }
  if(shingi){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}