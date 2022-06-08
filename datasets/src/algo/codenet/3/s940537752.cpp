#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
#define SIZE 100001
int n,a[SIZE],b[SIZE],c[SIZE];

bool check(int c,int a){
  if(c<a) return 1;
  else return 0;
}

int binary_search(int a, int *v){
  int lb=0,ub=n,mid;
  if(check(v[0],a)){
    while(ub-lb>1){
      mid=(lb+ub)/2;
      (check(v[mid],a)?lb:ub)=mid;
    }
    return lb;
  }
  return -1;
}

int main(){
  int ans=0;cin>>n;
  //配列
  REP(i,n) cin>>a[i];
  REP(i,n) cin>>b[i];
  REP(i,n) cin>>c[i];
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);
  
  REP(i,n){
    int tmp=c[i],numb,numa;
    numb=binary_search(tmp,b);
    //cout<<"ci"<<tmp<<" numb"<<numb<<endl;
    if(numb==-1) continue;
    else REP(j,numb+1){
      numa=binary_search(b[j],a);
      if(numa!=-1) ans+=numa+1;
      //cout<<"numa"<<numa<<" ans+"<<numa+1<<endl;
    }
  }

  cout<<ans;
}