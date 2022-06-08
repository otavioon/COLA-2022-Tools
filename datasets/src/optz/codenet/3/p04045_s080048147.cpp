#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

unordered_set<long> st;

bool isok(long i) {
  while (true) {
    if (i == 0) return true;
    long tmp = i % 10;
    if (st.count(tmp)) return false;
    i /= 10;
  }
}

void solve() {
  long N, K;
  cin >> N >> K;
  rep (i, K) {
    long d;
    cin >> d;
    st.insert(d);
  }
  for (long i = N;; i++) {
    if (isok(i)) {
      cout << i << endl;
      return;
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
