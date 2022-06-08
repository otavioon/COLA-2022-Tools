#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n,k;
  cin >> n >> k;
  set<int> banned;
  rep(i,k) {
    int s; cin >> s;
    banned.insert(s);
  } 
  for (int i = n; i <= 10*n; i++)
  {
    int now = i;
    bool ok = true;
    while (now > 0)
    {
      if (banned.count(now%10) == 1) {
        ok = false;
        break;
      }
      now /= 10;
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}