#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vec vector
#define vi vec<int>
#define vvi vec<vec<int>>
#define ALL(a) begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)
#define SORT(a) stable_sort(ALL(a))
#define RSORT(a) stable_sort(RALL(a))
#define REV(a) reverse(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), end(a))
#define lambda(i) [](auto& i)
#define compare(i, j) [](auto& i, auto& j)
#define min_of(a) *min_element(ALL(a))
#define max_of(a) *max_element(ALL(a))
#define sum(a) accumulate(ALL(a), 0)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(a) (int)(a).size()
#define REP(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define RREP(i, n) for (auto i = n - 1; i != static_cast<decltype(i)>(-1); i--)
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (auto i = b - 1; i != a; i--)
#define EACH(i, a) for (auto&& i: (a))
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;

struct union_find {
  vi data;
  union_find(int size) : data(size, -1) { }
  bool union_set(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find_set(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

vi cum(vi V) {
  vi U(SZ(V));
  partial_sum(ALL(V), begin(U));
  return U;
}

void solve() {
  int n;
  int ans = 0;

  cin >> n;
  vi a(n), b(n), c(n), b_a(n + 1);
  REP(i, n) {
    cin >> a[i];
  }
  REP(i, n) {
    cin >> b[i];
  }
  REP(i, n) {
    cin >> c[i];
  }
  SORT(a);
  SORT(b);
  SORT(c);
  REP(i, n) {
    int index = lower_bound(ALL(a), b[i]) - begin(a);
    b_a[i] += index;
    b_a[i + 1] = b_a[i];
  }
  REP(i, n) {
    int index = lower_bound(ALL(b), c[i]) - begin(b);
    if (index < 1) continue;
    ans += b_a[index - 1];
  }

  cout << ans << endl;
  // REP(i, n) {
  //   cout << v[i];
  // }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  solve();
}
