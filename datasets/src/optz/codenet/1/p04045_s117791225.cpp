#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1001001001
#define LINF (1LL << 62)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solv() {
    int N, K;
    vector<bool> hateNumber(10);
    cin >> N >> K;
    rep(i, 10) hateNumber[i] = false;
    rep(i, K) {
        int buf;
        cin >> buf;
        hateNumber[buf] = true;
        //   cout << hateNumber[i];
    }
    // cout << endl;
    int ans = N;
    while (true) {
        bool flag = true;
        int buf = ans;
        while (buf != 0) {
            if (hateNumber[buf % 10] == true) {
                flag = false;
                break;
            }
            buf /= 10;
        }
        if (flag) {
            cout << ans << endl;
            return;
        }
        ans++;
    }
}

int main() {
    solv();
    return 0;
}