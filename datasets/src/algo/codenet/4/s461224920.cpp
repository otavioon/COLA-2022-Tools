#include <iostream>
#include <set>

using namespace std;

set<int> f(int x) {
  set<int> s;
  if (x == 0) s.insert(0);
  while (x > 0) {
    s.insert(x % 10);
    x /= 10;
  }
  return s;
}

bool has_common(const set<int> &a, const set<int> &b) {
  auto ai = a.begin(), bi = b.begin();
  while (ai != a.end() && bi != b.end()) {
    if (*ai < *bi) ai++;
    else if (*ai > *bi) bi++;
    else return true;
  }
  return false;
}

int main() {
  int N, K;
  cin >> N >> K;

  set<int> D;
  for (int i = 0; i < K; ++i) {
    int d;
    cin >> d;
    D.insert(d);
  }

  while (has_common(D, f(N))) N++;

  cout << N << endl;
}
