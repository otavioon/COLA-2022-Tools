#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N){
        cin >> A[i];
    }
    rep(i, N){
        cin >> B[i];
    }
    rep(i, N){
        cin >> C[i];
    }

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    long long ans = 0;
    rep(i, N){
        long long a;
        a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        long long c;
        c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += a*c;
    }

    cout << ans << endl;

}