#include<bits/stdc++.h>
using namespace std;

#define mfor(i,a,b) for(int i=(a);i<=(b);i++)

set<int> D;

bool dislikes(int N) {
    while (N) {
        if (D.count(N % 10))
            return true;
        N /= 10;
    }
    return false;
}

void solve() {
    int N, K; cin >> N >> K;

    mfor(i, 1, K) {
        int d; cin >> d;
        D.insert(d);
    }

    while (dislikes(N))
        N++;

    cout << N << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}