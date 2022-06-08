//#pragma GCC optimize("O3")

#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

/*----------macros----------*/

//output================
#define endl '\n'
#define fcout(a) cout << fixed << setprecision((int)(a))

//typedef===============
typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  Pii;
typedef pair<ll, ll>    Pll;

//const number==========
constexpr ll INF9   = (ll)1e9 + 1;
constexpr ll INF18  = (ll)1e18 + 1;
constexpr ll MOD    = 1000000007;
constexpr ll MOD2   = 998244353;
constexpr ld PI     = 3.141592653589793L;

//member================
#define pb push_back
#define eb emplace_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

//others================
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define rep(i, n)       for(int i = 0; (i) < (n); ++(i))
#define reps(i, n)      for(int i = 1; (i) <= (n); ++(i))
#define rrep(i, n)      for(int i = n - 1; (i) >= 0 ; --(i))
#define repbit(bit, n)  for(int bit = 0; (bit) < (1 << (n)); ++(bit))
#define ifbit(bit, i)   if((bit) & (1 << (i)))
#define CtoI(c)         int((c)) - int('0')
#define ItoC(c)         char((c) + '0')

//functions=============
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

//vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
//vector<int> dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };

/*--------additional--------*/



/*----------main------------*/

int main() {
/*----------fastio----------*/
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
/*----------solve-----------*/

    int N; cin >> N;
    vector<long long> L(N);
    for (int i = 0; i < N; ++i) cin >> L[i];
    sort(L.begin(), L.end());

    long long res = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
            res += max(k - (j+1), 0);
        }
    }
    cout << res << endl;
return 0;
}