#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int ans = 1;
  int b = 0;
  
  cin >> N;
  vector<int> vec(N);
  vector<bool> check(N);

  for(int i=0;i<N;++i){
    cin >> vec.at(i);
  }
  while(vec.at(b) != 2){
    if(check.at(b) == true){
      cout << -1 << endl;
      return 0;
    }else{
      ans += 1;
      check.at(b) = true;
      b = vec.at(b) - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
