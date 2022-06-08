#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<bool> flag(10,true);
  int D;
  for(int i=0;i<K;i++){
    cin >> D;
    flag.at(D)=false;
  }
  string S;
  int j;
  for(int i=N;;i++){
    S=to_string(i);
    for(j=0;j<S.size();j++){
      if(!flag.at(S.at(j)-'0')){
        break;
      }
    }
    if(j==S.size()){
      cout << i << endl;
      return 0;
    }
  }
}
