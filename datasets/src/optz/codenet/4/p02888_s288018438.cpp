#include <bits/stdc++.h>
using namespace std;

long long n, a[2010], k, ans = 0;
vector<long long> b;

int main() {
    memset(a, 0, sizeof(a));
    scanf("%lld", &n);
    for(long long i = 0; i < n; i++) scanf("%lld", &k), a[k]++, b.push_back(k);
    for(long long i = 1; i <= 2000; i++) a[i] += a[i-1];
    for(long long i = 0; i < b.size(); i++) {
        for(long long j = i+1; j < b.size(); j++) {
            long long c = b[i], d = b[j];
            if(c == d && a[d] - a[d-1] > 1) ans += a[c+d-1] - a[d-1] - 2;
            else if(c < d) ans += a[c+d-1] - a[d-1] - 1;
            else ans += a[c+d-1] - a[c-1] - 1;
        }
    }
    printf("%lld", ans);
}
