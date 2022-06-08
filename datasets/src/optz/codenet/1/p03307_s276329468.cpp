#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<=N;i++)


signed main(){
  int N;
  cin>>N;
  rep(i,10000000000){
    if(i%2==0&&i%N==0){
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}