#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<int> bccount(N, 0);
    for (int i = 0; i < N; i++) {
        auto iter = upper_bound(C.begin(), C.end(), B[i]);
        bccount[i] = N - distance(C.begin(), iter);
    }
    for (int i = N - 1; i > 0; i--) {
        bccount[i-1] += bccount[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto iter = upper_bound(B.begin(), B.end(), A[i]);
        if (iter == B.end()) break;
        ans += bccount[distance(B.begin(), iter)];
    }
    cout << ans << endl;
}