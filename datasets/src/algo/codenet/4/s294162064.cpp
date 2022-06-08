#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, k;
  cin >> n >> k;
  set<int> a;
  rep(i,k) {
    int x; cin >> x;
    a.insert(x);
  }
  int ans = n;
  while(ans<100100) {
    int num = ans;
    bool ch = true;
    while(ch&&num>0) {
      if(a.count(num%10)) ch = false;
      num /= 10;
    }
    if(ch) {
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
  return 0;
}