#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  vector<int> A(N), B(N), C(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  ll ans = 0;
  for (int j = 0; j < N; j++) {
    int b = B[j];
    int a = lower_bound(A.begin(), A.end(), b) - A.begin();
    if (a == 0) continue;
    int c = upper_bound(C.begin(), C.end(), b) - C.begin();
    if (C[c] == inf) continue;
    ans += a * (N - c);
  }
  cout << ans << endl;

  return 0;
}
