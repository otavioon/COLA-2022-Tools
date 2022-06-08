#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define MAXN 100005
using namespace std;
int a[MAXN], b[MAXN], c[MAXN];
int n;
inline void read() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
}

inline int searcha(int x) {
    int l = 1, r = n, mid;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(a[mid] > x)
            r = mid - 1;
        else 
            l = mid + 1;
    }
    l --;
    if(a[l] == x) l --;
    return l;
}
inline int searchc(int x) {
    int l = 1, r = n, mid;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(c[mid] > x)
            r = mid - 1;
        else 
            l = mid + 1;
    }
    l --;
    return n-l;
}

int main() {
 
    long long ans = 0;
    int loc1, loc2;
    read();
    sort(a+1, a+1+n);
    sort(c+1, c+1+n);
    for(int i = 1; i <= n; i++) {
        loc1 = searcha(b[i]);
        loc2 = searchc(b[i]);
        ans += loc1*loc2;
    }
    cout << ans << "\n";
    return 0;
}