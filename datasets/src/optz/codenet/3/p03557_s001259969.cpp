#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 100100100100100100;
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    int n; cin >>n;
    vector<int> a(n); REP(i,n) cin >> a[i];
    vector<int> b(n); REP(i,n) cin >> b[i];
    vector<int> c(n); REP(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<ll> bc(n);
    for (int i = 0; i < n; i++) {
        int thisb = b[i];
        int ok = n;
        int ng = -1;
        while (abs(ok - ng) > 1) {
            int m = (ok+ng)/2;
            if (c[m] > thisb) {
                ok = m;
            } else {
                ng = m;
            } 
        }
        bc[i] = (ll)(n - ok);
    }

    vector<ll> cumbc(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        cumbc[i] = cumbc[i+1] + bc[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        int thisa = a[i];
        int ok = n;
        int ng = -1;
        while (abs(ok - ng) > 1) {
            int m = (ok+ng)/2;
            if (b[m] > thisa) {
                ok = m;
            } else {
                ng = m;
            } 
        }
        res += cumbc[ok];
    }

    cout << res << endl;
    return 0;
}
