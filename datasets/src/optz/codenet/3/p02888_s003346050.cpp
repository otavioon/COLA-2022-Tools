#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }

template <typename X>
X BinSearch(X left, X right, function<bool(X)> judge, bool lower = true, X eps = 1) {
    while (right - left > eps) {
        X mid = (right + left) / 2;
        if (judge(mid) == lower) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return lower ? right : left;
}

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for(auto &x : L) cin >> x;
    sort(WHOLE(L));
    i64 ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            int k_lower = BinSearch<int>(j, N, [&](int k) -> bool {
                return L[j] - L[i] < L[k];
            }, true);
            int k_upper = BinSearch<int>(j, N, [&](int k) -> bool {
                return L[k] < L[i] + L[j];
            }, false);
            ans += max(0, k_upper - k_lower + 1);
        }
    }
    cout << ans << endl;
    return 0;
}