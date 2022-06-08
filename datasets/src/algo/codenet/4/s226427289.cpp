#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VS = vector<string>;
#define rep(start, end) for(int loop_var = start; loop_var <= end; ++loop_var)
#define repconref(container) for(auto& container_element: container)
#define all(container) begin(container), end(container)
#define ftl ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define intmap map<int, int>
#define intset set<int>
#define has(a, b) ((a.find(b) != a.end()) ? true : false)
bool ok(int n, const intset& d) {
    while(n) {
        int x = n % 10;
        if(has(d, x))
            return false;
        n /= 10;
    }
    return true;
}

int main() {
    ftl;
    int n, k;
    cin >> n >> k;
    intset d;
    rep(0, k - 1) {
        int x;
        cin >> x;
        d.insert(x);
    }
    while(true) {
        if(ok(n, d)) {
            cout << n; return 0;
        }
        ++n;
    }
    return 0;
}