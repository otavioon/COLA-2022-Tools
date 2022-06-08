#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N), B(N), C(N);

    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> B[i]; }
    rep(i, N) { cin >> C[i]; }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long ans = 0;
    long long greaterCnt = 0;
    map<long long, long long> cntmap;
    for (long long i = N - 1; i >= 0; i--) {
        greaterCnt += C.end() - upper_bound(C.begin(), C.end(), B[i]);
        cntmap[B[i]] = greaterCnt;
    }
    rep(i, N) {
        vector<long long>::iterator iter = upper_bound(B.begin(), B.end(), A[i]);
        if (iter != B.end()) {
            ans += cntmap[*iter];
        }
    }
    cout << ans << endl;

    return 0;
}
