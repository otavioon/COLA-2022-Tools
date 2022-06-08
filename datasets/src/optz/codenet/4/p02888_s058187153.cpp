#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    REP(i, n) cin >> L[i];
    // int n = 2000;
    // vector<int> L(n);
    // random_device rnd;
    // REP(i,n)L[i] = rnd() % 100;


    sort(L.begin(),L.end(),greater<int>());
    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if((L[i] < L[j] + L[k]))
                    ans++;
            }
        }
    }
    cout << ans << endl;
}
