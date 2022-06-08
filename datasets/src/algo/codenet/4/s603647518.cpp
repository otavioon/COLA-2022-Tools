#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    rep(i, k) cin >> d[i];
    for (int i = n; i <= n * 10; ++i) {
        int num = i;
        set<int> st;
        while(1) {
            if (num == 0) break;
            st.insert(num % 10);
            num /= 10;
        }
        bool ok = true;
        for (auto dd: d) {
            if (st.count(dd) != 0) {
                ok = false;
                break;
            } 
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
