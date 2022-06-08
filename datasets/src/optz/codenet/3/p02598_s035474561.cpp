// https://atcoder.jp/contests/abc174/tasks/abc174_e
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

template <typename T, typename F>
T binarySearch(T ok, T ng, F isOK, T bound = 1) {
    while (abs(ng - ok) > bound) {
        T m = (ng + ok) / 2;
        if (isOK(m))
            ok = m;
        else
            ng = m;
    }
    return ok;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N) { cin >> A[i]; }

    // 全ての丸太を長さtarget以下にする
    auto fn = [&](int target) {
        int cnt = 0;
        REP(i, N) {
            // 例えば長さ7を7以下にするなら切らなくていい。
            // 7未満にするなら1回切るように数える。
            cnt += CEIL(A[i], target) - 1;
            if (cnt > K) {
                break;
            }
        }
        // 戻り値はboolean
        return cnt <= K;
    };
    // 二分探索で求める。正解の範囲は(ng+1)以上ok以下
    int ng = 0, ok = 1e9;
    cout << binarySearch(ok, ng, fn) << endl;

    return 0;
}
