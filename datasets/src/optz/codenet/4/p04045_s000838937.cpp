#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, k;
int main() {
    cin >> n >> k;
    vector<bool> d(10, true);
    for(int i = 0; i < k; ++i) {
        int din;
        cin >> din;
        d.at(din) = false;
    }

    int ans = 0;
    for(int i = n; i <= 10*n; ++i) {
        int check = i;
        string scheck = to_string(check);
        int slen = scheck.length();
        bool flg = true;
        for(int i = 0; i < slen; ++i) {
            if(!d.at(scheck.at(i)-'0')) {
                flg = false;
                break;
            }
        }
        if(flg) {
            ans = check;
            break;
        }
    }

    cout << ans << endl;
}