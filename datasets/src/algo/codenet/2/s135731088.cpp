#define CIN_ONLY 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const int MOD = 1000000007;
const ld PI = acos(ld(-1));
int fix(ll n) { return (n % MOD + MOD) % MOD; }
int fix(ll n, int MOD) { return (n % MOD + MOD) % MOD; }

int getLeast(int n)
{
  int pow2 = 1 << 30;
  while (pow2) {
    if (n & pow2) {
      return pow2 << 1;
    }
    pow2 >>= 1;
  }
  return 0;
}

int main()
{
  if (CIN_ONLY) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int n;
  cin >> n;
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    s.insert(v); 
  }
  int ans = 0;
  while (!s.empty()) {
    auto it = s.rbegin();
    int a = *it;
    int b = getLeast(a) - a;
    s.erase(next(it).base());
    auto it2 = s.find(b);
    if (it2 != s.end()) {
      s.erase(it2);
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
