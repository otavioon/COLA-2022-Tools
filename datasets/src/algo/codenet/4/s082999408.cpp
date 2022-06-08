#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 30;

set<int> kirai;

bool haraeru(int n) {
  bool res = true;
  string s = to_string(n);
  for (int i = 0; i < s.size(); i++) {
    if (kirai.count(s[i])) res = false;
  }
  return res;
}

// ====================================================================

int main() {
  int n, k;
  cin >> n >> k;
  char a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    kirai.insert(a);
  }

  int ans = n;
  while (!haraeru(n)) {
    n++;
  }
  cout << n << endl;
}
