#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;


int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));

  ll ans = 0;
  rep(i, n){
    auto x = lower_bound(ALL(a), b[i]);
    auto y = upper_bound(ALL(c), b[i]);
    int w = x - a.begin();
    int z = c.end() - y;
    ans += w * z;
  }
  cout << ans << endl;
}