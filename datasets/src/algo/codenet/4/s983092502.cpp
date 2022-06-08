#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int keta(int64_t x){
  int count=1;
  while(x/10!=0){
    x/=10;
    count++;
  }
  return count;
}

int main() {
  int N,K; cin>>N>>K;
  vector<bool> S(10,false);
  rep(i,K) {
    int s;
    cin>>s;
    S.at(s)=true;
  }
  for(int i=N;i<1000000;i++){
    int a=keta(i),b=i;
    bool ans=true;
    rep(j,a){
      int c=b%10;
      if(S.at(c)) ans=false;
      b/=10;
    }
    if(ans){
      cout<<i;
      break;
    }
  }
}
