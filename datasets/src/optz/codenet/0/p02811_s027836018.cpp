#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <numeric>
#include <string.h>
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define repn(i, x) for (int i = 1; i <= (int)(x); i++)
#define repr(i, x) for (int i = ((int)(x) - 1); i >= 0; i--)
#define reprn(i, x) for (int i = ((int)(x)); i > 0; i--)
#define all(x) (x).begin(),(x).end()
typedef long long int64;
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

//逆元を求める関数
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
      finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
//組み合わせ
long long COM (int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

void solve() {
		int k, x; cin >> k >> x;
		cout << (500 * k >= x ? "Yes" : "No") << endl;
    return;
}

int main() {
    solve();
    return 0;
}

