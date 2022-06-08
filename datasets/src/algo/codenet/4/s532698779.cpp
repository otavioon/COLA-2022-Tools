#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
using i64 = int64_t;
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    set<int> s;
    for(int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    string ans = "";
    for(int d = 0; N > 0; d++) {
        if(s.count(N % 10)) {
            N++;
        } else {
            ans += to_string(N % 10);
            N /= 10;
        }
    }
    reverse(WHOLE(ans));
    cout << ans << endl;
    return 0;
}