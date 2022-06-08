#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    multiset<ll> a;
    REP(_, n) {
        ll tmpa; cin >> tmpa; a.insert(tmpa);
    }
    ll ans = 0;
    while(!a.empty()) {
        ll a1 = *(--a.end());
        a.erase(--a.end());
        ll pow2=1, tmp=1;
        while (a1 >= pow2) {
            pow2 <<= 1; tmp++;
        }
        ll a2 = pow2 - a1;
        if (a.find(a2) != a.end()) {
            a.erase(a.find(a2));
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
