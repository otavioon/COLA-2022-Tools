#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> bad;
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; i++){
    int x;
    cin >> x;
    bad.insert(x);
  }
  int ans = N;
  bool ok = false;
  while(ok == false){
    ok = true;
    int test = ans;
    while(test>0){
      int digit;
  	  digit = test % 10;
      if(bad.find(digit) != bad.end()){
        ok = false;
        break;
      }
      test /= 10;
    }
    if(ok == true){
      cout << ans << endl;
	  break;
    }
    ans++;
  }
  return 0;
}
