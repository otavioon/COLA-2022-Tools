#include <bits/stdc++.h>
using namespace std;

int upper_b(int x){
  int cnt=1;
  while(x){
    x/=2;
    cnt*=2;
  }
  return cnt;
}

int main(){
  int N,a,ans=0;
  cin>>N;
  multiset<int> S;
  for(int i=0;i<N;i++){
    cin>>a;
    S.insert(a);
  }
  auto it=S.end();
  while(!S.empty()){
    it=S.end();
    it--;
    a=upper_b(*it);
    a-=*it;
    S.erase(it);
    
    it=S.find(a);
    if(it!=S.end()){
      S.erase(it);
      ans++;
    }
  }
  cout<<ans<<endl;
}