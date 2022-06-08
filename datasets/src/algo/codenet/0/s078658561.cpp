#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int N = s.size(), K; cin >> K;
    long long ans = 0;
    int c = 1, a = 0, b = 0;
    for(int i=1; i<N; i++) {
        if(s[i] == s[i-1]) {
            ++c;
        }
        else {
            if(i - c == 0) {
                ans += c / 2;
                a = c;
                c = 1;
            }
            else {
                ans += 1LL * K * (c / 2);
                c = 1;
            }
        }
        if(i+1 == N) {
            ans += c / 2;
            b = c;
        }
    }
    if(b == N) return !printf("%lld", 1LL*K*N/2);
    if(s[0] == s[N-1]) ans += 1LL * (K-1) * (a+b) / 2;
    else ans += 1LL * (K-1) * (a/2 + b/2);
    printf("%lld", ans);
    return 0;
}
