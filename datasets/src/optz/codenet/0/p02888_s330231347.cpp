#include <bits/stdc++.h>
using namespace std;

int n, a[2010], e[2010], k, ans = 0;
vector<int> b;

int main() {
    memset(a, 0, sizeof(a));
    memset(e, 0, sizeof(e));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &k), a[k]++, e[k] = 1;
    for(int i = 1; i <= 2000; i++) {
        if(a[i]) b.push_back(i);
        a[i] += a[i-1];
        e[i] += e[i-1];
    }
    for(int i = 0; i < b.size(); i++) {
        for(int j = i; j < b.size(); j++) {
            int c = b[i], d = b[j];
            if(c == d) {
                if(a[d] - a[d-1] > 1) ans += e[c+d-1] - e[d];
            }
            else ans += e[c+d-1] - e[d];
            if(c == d) ans += (a[d] - a[d-1] > 2);
            else ans += (a[d] - a[d-1] > 1);
        }
    }
    printf("%d", ans);
}
