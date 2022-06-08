#include<bits/stdc++.h>
using namespace std;
int main() {
  set<int> s;
  for(int i = 0; i < 10; ++i) {
    s.insert(i);
  }
  string N;
  int K, x;
  cin >> N >> K;
  int nn = stoi(N);
  for(int i = 0; i <= K; ++i) {
    cin >> x;
    s.erase(x);
  }
  bool flag = false, papa=false;
  int now;
  int ans = 0;
  for(int i = 0; N[i]; ++i) {
    if(flag) ans = ans*10 + *s.begin();
    else {
      if(s.lower_bound(N[i]-'0') == s.end()) {
        papa = true;
        break;
      }
      now = *s.lower_bound(N[i]-'0'); 
      //cout << now << ' ';
      ans = ans*10 + now;
      if(now > (N[i]-'0')) flag = true;
    }
  }
  //puts("");
  if(papa) {
    int fst = *s.upper_bound(0);
    cout << "fst=" << fst<< endl;
    for(int i = 0; N[i]; ++i) {
      fst = fst*10 + *s.lower_bound(0);
    }
    cout << fst << endl;
  } else {
    cout << ans << endl;
  }
}
