#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1e12

#define PB push_back
#define PF push_front
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpi vector<pii>
#define vll vector<ll>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pr_d(x) cout << fixed << setprecision(15) << x << endl
#define ud(c, x) distance(c.begin(), upper_bound(all(c), x))
#define ld(c, x) distance(c.begin(), lower_bound(all(c), x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep3(i, n) for (int i = (n - 1); i >= 0; --i)
#define rep4(i, a, b) for (int i = (a); i > (b); --i)
#define pb push_back
#define out(x) cout << x << "\n"
bool odd(int i) { return i % 2; }

#define all(v) v.begin(), v.end()
#define size(x) int(x.size())

int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void Yes_No(bool f) {
  if (f)
    printf("Yes\n");
  else
    printf("No\n");
}

void deb_p(pii p) { printf("pair = %d %d\n", p.fi, p.se); }
void deb_i(int i) { printf("i = %d\n", i); }
void deb_v(vector<int> v) {
  printf("v = ");
  for (auto i : v) printf("%d ", i);
  printf("\n");
}
template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
//-------------------ここから回答する-----------------------

void solve(void) {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i], --a[i];
  int x = a[0], cta = 0;
  set<int> st;
  while (a[x] != 1 || st.find(a[x]) == st.end()) st.insert(x), x = a[x], ++cta;
  if (a[x] == 1)
    out(--cta);
  else
    out(-1);
}
int main(void) { solve(); }
