#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());

    int ans = 0;
    for (int a = 0; a < N - 1; a++) {
        for (int b = a + 1; b < N; b++) {
            int dist = lower_bound(L.begin(), L.end(), L[a] + L[b]) - L.begin();
            ans += dist - b - 1;
        }
    }
    cout << ans << '\n';
}
