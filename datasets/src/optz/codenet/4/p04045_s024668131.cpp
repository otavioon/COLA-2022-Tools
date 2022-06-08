#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

int n, k;
int dislikes[10];
int digits[20];
int res[20];
int done;

void solve(int d, int bigger, int non_leading_zero) {
    if (done) return;
    if (d < 0) {
        done = 1;
        return;
    }
    for (int k = 0; k < 10; ++k) {
        if (dislikes[k]) {
            if (k != 0 || non_leading_zero) continue;
        }
        if (bigger) {
            res[d] = k;
            solve(d - 1, bigger, non_leading_zero || k);
            if (done) return;
        } else {
            if (k == digits[d]) {
                res[d] = k;
                solve(d - 1, 0, non_leading_zero || k);
                if (done) return;
            } else if (k > digits[d]) {
                res[d] = k;
                solve(d - 1, 1, non_leading_zero || k);
                if (done) return;
            }
        }
    }
}

int main () {
    int i, j;
    n = getint(), k = getint();
    for (i = 0; i < k; ++i) dislikes[getint()] = 1;
    for (i = 0; ; ++i) {
        if (!n) break;
        digits[i] = n % 10, n /= 10;
    }
    solve(18, 0, 0);
    int on = 0;
    for (i = 18; ~i; --i) {
        if (on) cout << res[i];
        else if (res[i]) {
            on = 1, cout << res[i];
        }
    }
    puts("");
    return 0;
}
