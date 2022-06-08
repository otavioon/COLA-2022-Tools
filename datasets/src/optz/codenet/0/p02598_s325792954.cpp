#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

#define Maxn 200010
#define LL long long

using namespace std;

const double eps = 0.00001;

inline LL read() {
    LL x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

LL n, k, a[Maxn], maxone;

LL calc(int len) {
    LL tim = 0;
    for(int i = 1; i <= n; ++i) {
        tim += (a[i] - 1) / len;
    }
    return tim;
}

int main() {
    n = read(); k = read();
    for(int i = 1; i <= n; ++i) a[i] = read(), maxone = max(maxone, a[i]);
    int l = 0, r = maxone;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(calc(mid) > k) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}