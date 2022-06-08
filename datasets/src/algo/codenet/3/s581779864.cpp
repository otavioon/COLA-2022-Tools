#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);

    // B固定で考える
    int count = 0;
    //　N^2
    rep(i, N) {  // Bのループ

        int Acount = 0;
        rep(j, N) {  // Aのループ
            if (A.at(j) < B.at(i)) {
                Acount++;
            }
        }

        int Ccount = 0;
        rep(j, N) {  // Cのループ
            if (B.at(i) < C.at(j)) {
                Ccount++;
            }
        }

        count += Acount * Ccount;
    }

    cout << count << endl;

    return 0;
}