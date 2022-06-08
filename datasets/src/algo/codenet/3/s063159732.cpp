#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;
    vector<int> B(n);
    for (int &x : B) cin >> x;
    vector<int> C(n);
    for (int &x : C) cin >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++) { // 真ん中のループ
        int AtoB = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] < B[i]) {
                AtoB++;
            }
        }
        int BtoC = 0;
        for (int j = 0; j < n; j++) {
            if (C[j] > B[i]) {
                BtoC++;
            }
        }
        cnt += AtoB * BtoC;
    }

    cout << cnt << endl;

    return 0;
}
