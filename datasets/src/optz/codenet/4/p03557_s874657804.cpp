#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                         \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z     \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  std::vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }

  sort(all(A));
  sort(all(C));

  ll cnt = 0;
  rep(j, N) {
    ll d1 = lower_bound(A.begin(), A.end(), B.at(j)) - A.begin();
    ll d2 = C.end() - upper_bound(C.begin(), C.end(), B.at(j));
    cnt += d1 * d2;
  }

  cout << cnt << '\n';
}
