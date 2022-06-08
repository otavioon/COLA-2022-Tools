#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    ll K; cin >> K;
    ll N = S.size();
    // printf("%s\n", S.c_str());
    if (N == 1) {
        cout << K / 2 << endl;
        return 0;
    }

    // If all of the characters of S are the same, speciall
    bool same = true;
    rep(i,N) if (S[0] != S[i]) {same = false; break;}
    if (same) {
        N = N * K;
        cout << N/2 << endl;
        return 0;
    }

    // separate top and tail same characters
    string S1, S2;
    int a = 0, b = 0;
    if (S.at(0) == S.at(N-1)) {
        for (ll i = 0; i < N; i++) {
            if (S.at(0) == S.at(i)) {S1.push_back(S.at(i));}
            else break;
        }
        for (ll i = N-1; i >= 0; i--) {
            if (S[N-1] == S[i]) {S2.push_back(S[i]);}
            else break;
        }
        a = S1.size();
        b = S2.size();
    }

    ll cnt = 0, cnt2 = 0;;
    rep(i,N-1) {
        if (S[i] == S[i+1]) {
            int j = i + 1;
            while (j < N && S[i] == S[j]) j++;
            int num = j - i;
            for (int k = i+1; k < j; k+=2) S[k]++, cnt++;
            if (j < N && num % 2 == 0 && S[j-1] == S[j]) S[j-1]++;
        }
    }
    cnt2 = a / 2 + b / 2 - (a + b) / 2;
    // printf("%s\n", S.c_str());
    // printf("cnt2 = %ld\n", cnt2);

    cout << cnt * K - cnt2 * (K-1) << endl;
}
