#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    long long K; cin >> K;
    long long ans = 0;
    bool alleq = true;
    for (int i = 1; i < s.size(); i++)
        if (s[0] != s[i]) { alleq = false; break; }
    if (alleq) {
        cout << (K * s.size()) / 2 << endl;
    } else {
        const int n = s.size();
        int i = 0, j = n-1;
        while (s[0] == s[i]) i++;
        while (s[j] == s[n-1]) j--;
        for (int k = i, c = 1; k <= j; k++) {
            if (k == j || s[k] != s[k+1]) { ans += (long long)c/2 * K; c = 1; }
            else c++;
        }
        cout << ans + i/2 + (n-j-1)/2 + (long long)(i+n-j-1)/2*(K-1) << endl;
    }
}
