#include <iostream>
#include <map>

using namespace std;

int mypow(int b, int n) {
    if (n == 0) return 1;
    if (n == 1) return b;
    if (n % 2 == 0) {
        return mypow(b * b, n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

// n < 2^kなる最小の2^kを返す
int minbeki(int n) {
    int ret = 1;
    while (n >= ret) {
        ret *= 2;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    map<int, int> cnt;
    // 値とボールの個数を管理

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (cnt.find(a) == cnt.end()) cnt[a] = 0;
        ++cnt[a];
    }

    int ans = 0;

    // cntをkeyが大きい方から見ていく
    for (auto itr = cnt.rbegin(); itr != cnt.rend(); ++itr) {
        int b = itr->first;
        if (cnt[b] == 0) continue;

        int a = minbeki(b) - b;
        // bとペアになりうるaを求める

        if (a == b) {
            // bと書かれたボール同士でペアを作る
            ans += cnt[b] / 2;
        } else {
            if (cnt.find(a) == cnt.end()) continue;
            // aと書かれたボールが存在しなければ次へ

            // 少ない方に合わせてペアを作る
            ans += min(cnt[a], cnt[b]);
            cnt[a] -= min(cnt[a], cnt[b]);
        }
    }

    cout << ans << endl;
    return 0;
}
