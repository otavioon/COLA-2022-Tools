#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }

bool is_ok(ll ans, set<int>& D) {
    string S = to_string(ans);
    rep(i, S.size()) {
        if (D.count(S[i] - 0x30) > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    set<int> D;
    rep(i, K) {
        int d;
        cin >> d;
        D.insert(d);
    }

    ll ans = N;
    while (1) {
        if (is_ok(ans, D)) break;
        ans++;
    }

    cout << ans << endl;
    return 0;
}