#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a, b;
    int E[10][10] = {};
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        E[a][b] = E[b][a] = 1;
    }

    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        order[i] = i + 1;
    }
    int ans = 0;
    do {
        int i = 0;
        for (i = 0; i < N - 1; i++) {
            if (!E[order[i]][order[i + 1]] == 0) break;
        }
        if (i == N - 1) ans++;
    } while (next_permutation(order.begin() + 1, order.end()));

    cout << ans << endl;
    return 0;
}