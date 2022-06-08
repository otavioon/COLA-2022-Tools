#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define stl_repr(itr, x) for (auto itr = x.rbegin(); itr != x.rend(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

using llong = long long int;

const static int MOD = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = 1LL << 62;
const static int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0); 
    ios::sync_with_stdio(false);

    string S;
    llong k;
    cin >> S >> k;

    llong cnt = 1, ans = 0;
    if (S[0] == S[(int)S.size() - 1]) {
        bool flag_all_same_char = true;
        for (int i = 0; i < (int)S.size() && flag_all_same_char; ++i) {
            if (S[i] != S[0]) {
                flag_all_same_char = false;
            }
        }

        if (flag_all_same_char) {
            ans = (int)S.size() * k / 2;
        } else {
            llong tmp1 = 1, tmp2 = 1;
            for (int i = 0; i < (int)S.size() - 1; ++i) {
                if (S[i] == S[i + 1]) ++tmp1;
                else break;
            }
            for (int i = (int)S.size() - 1; i > 0; --i) {
                if (S[i] == S[i - 1]) ++tmp2;
                else break;
            }

            for (int i = tmp1; i < (int)S.size() - tmp2; ++i) {
                if (S[i] == S[i + 1]) {
                    ++cnt;
                } else {
                    ans += (cnt / (llong)2) * k;
                    cnt = (llong)1;
                }
            }
            ans += (cnt / (llong)2) * k;

            ans += tmp1 / 2 + tmp2 / 2;
            ans += ((tmp1 + tmp2) / 2) * (k - 1);
        }
    } else {
        for (int i = 0; i < (int)S.size(); ++i) {
            if (S[i] == S[i + 1]) {
                ++cnt;
            } else {
                // cout << S[i] << " " << S[i + 1] << " " << cnt << endl;
                ans += (cnt / (llong)2) * k;
                cnt = (llong)1;
            }
        }
        ans += (cnt / (llong)2) * k;
    }

    cout << ans << endl;

    return 0;
}