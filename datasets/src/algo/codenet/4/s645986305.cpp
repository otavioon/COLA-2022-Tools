#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// int n;
set<int> d;

int is_ng(int n) {
    // nがdに含まれている数字で構成されていないか判定
    while (n != 0) {
        int tn = n % 10;
        if (d.count(tn)) {
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main() {
    cout << fixed << setprecision(10);
    
    int n, k; cin >> n >> k;
    // set<int> d
    rep(i, k) {
        int a; cin >> a;
        d.insert(a);
    }
    while (is_ng(n)) {
        n += 1;
    }
    cout << n << endl;
    return 0;
}