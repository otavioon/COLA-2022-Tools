#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
// using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

#define MAX 200000

vector<int> T[MAX];
vector<int> ans(MAX);
int n, q;

void dfs(int u, int p) {
  for (int i = 0; i < T[u].size(); i++) {
    if (T[u][i] == p) continue;
    ans[T[u][i]] += ans[u];
    dfs(T[u][i], u);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  cin >> n >> q;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0, -1);
  rep(i, n) cout << ans[i] << " ";
  cout << endl;
  return 0;
}