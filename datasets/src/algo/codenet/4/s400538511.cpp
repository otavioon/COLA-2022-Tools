#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  set<int> s;
  for (int i=0;i<K;i++){
    int D;
    cin >> D;
    s.insert(D);
  }
  int ans;
  for (int i=N;i<100000;i++){
    int j=i,k=i;
    bool can=true;
    while (k>=1){
      if (s.count(k%10)){
        can=false;
        break;
      }
      else{
        k=k/10;
      }
    }
    if (can){
      ans=j;
      break;
    }
  }
  cout << ans<< endl;
}