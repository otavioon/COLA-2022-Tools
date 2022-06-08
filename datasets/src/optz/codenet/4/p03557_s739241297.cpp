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
  int minv = 0;
  a.push_back(minv);
  b.push_back(minv);
  c.push_back(minv);
  a.push_back(INF);
  b.push_back(INF);
  c.push_back(INF);
  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));

  ll ans = 0;
  for (int i = n; i >= 1; i--){
    int x = lower_bound(ALL(b), c[i]) - b.begin() - 1;
    for (int j = x; j >= 1; j--){
      int y = lower_bound(ALL(a), b[j]) - a.begin() - 1;
      ans += y;
    }
  }
  cout << ans << endl;
}