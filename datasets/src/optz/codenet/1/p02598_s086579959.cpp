#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int MAXN = 200010;

int N, K, A[MAXN];

bool check(LL v) {
    int KK = K;

    for (int i = 0; i < N; ++i) {
        KK -= ((A[i] + v - 1) / v - 1);
    }

    return KK >= 0;
}

void solver() {
    cin >> N >> K;
    for(int i = 0; i < N; ++i) cin >> A[i];

    LL L = 1, R = 1e9 +100, best = R;

    while(L <= R) {
        LL m = (L + R) / 2LL;
        if (check(m)) {
            best = m;
            R = m - 1;
        }
        else {
            L = m + 1;
        }
    }

    cout << best << '\n';
}

int main() {

    ios_base :: sync_with_stdio(0); cin.tie(NULL);

    int t;
    //cin >> t;
    t = 1;

    while(t--)
        solver();

    return 0;
}