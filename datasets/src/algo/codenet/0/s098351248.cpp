#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    string S; cin >> S;
    int K; cin >> K;
    bool all = true;
    rep(i, 1, S.size()) {
        if(S[i - 1] != S[i]) all = false;
    }
    if(all) {
        long long n = S.size() * K;
        cout << n / 2 << '\n';
        return;
    }
    string T = S + S;
    long long cnts = 0;
    rep(i, 1, S.size()) {
        if(S[i - 1] == S[i]) {
            cnts++;
            S[i] = 'A';
            ++i;
        }
    }
    long long cntt = 0;
    rep(i, 1, T.size()) {
        if(T[i - 1] == T[i]) {
            cntt++;
            T[i] = 'A';
            ++i;
        }
    }
    long long ans = 0;
    if(K == 1) ans = cnts;
    else if(K == 2) ans = cntt;
    else {
        long long dif = cntt - cnts;
        ans = cnts + dif * (K - 1);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
