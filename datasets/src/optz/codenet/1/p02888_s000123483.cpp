#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 2e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

ll a[10010];
ll b[10010];
ll c[10010];

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    REP(i,n) {
        cin >> a[i];
        b[a[i]]++;
    }
    
    //3
    for (int i = 1; i <= 1000; i++) {
        if (b[i] >= 3) ans++;
    }

//cout << ans << endl;

    for (int i = 1; i <= 2000; i++) {
        if (b[i] != 0) {
            c[i] = 1;
        }
        c[i] += c[i-1];
    }
    
    //2
    for (int i = 1; i <= 1000; i++) {
        if (b[i] >= 2) {
            ans += c[i * 2 - 1] - 1;
        }
    }

//cout << ans << endl;

    //1
    for (int i = 1; i <= 1000; i++) {
        if (b[i] == 0) continue;
        for (int j = i + 1; j <= 1000; j++) {
            if (b[j] == 0) continue;
            ll left = j + 1;
            ll right = j + i - 1;
            ans += c[right] - c[left - 1];
            if (left <= i && i <= right && b[i] >= 2) ans--;
            if (left <= j && j <= right && b[j] >= 2) ans--;
        }
    }

    cout << ans << endl;
}

int main(int argc, char *argv[]){
    // /* Regular */
    // int case_num = 1;
    // if (argc > 1 && stoi(argv[1])) cin >> case_num;
    // REP(case_no, case_num) {
    //   cerr << endl << "case " << case_no + 1 << endl;
    //   solve();
    // }
    /* AOJ */
    solve();
    return 0;
}