#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    long long K;
    cin >> S >> K;
    long long ans = 0;
    int len = S.length();
    if (len == 1) {
        printf("%lld\n", K / 2);
        return 0;
    }
    bool last = false;
    bool skip = false;
    for (int i = 1; i < len; i++) {
        if (skip) {
            skip = false;
            continue;
        }
        if (S[i] == S[i - 1]) {
            ++ans;
            skip = true;
            if (i == len - 1) {
                last = true;
            }
        }
    }
    ans *= K;
    if (S[0] == S[len - 1] && !last) {
        ans += K - 1;
    }
    printf("%lld\n", ans);

    return 0;
}
