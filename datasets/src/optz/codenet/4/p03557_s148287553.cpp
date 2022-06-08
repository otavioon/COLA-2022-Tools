#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N)scanf("%d", &A[i]);
    rep(i, N)scanf("%d", &B[i]);
    rep(i, N)scanf("%d", &C[i]);

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    int ans = 0;
    rep(i, N){
        int a;
        a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        int c;
        c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += a*c;
    }

    cout << ans << endl;

}