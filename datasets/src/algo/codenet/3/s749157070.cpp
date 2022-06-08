#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[110000], b[110000], c[110000], d[110000], n;

void funca(ll x, ll y){
    if (x == n) {
        return;
    } else if (b[x] < c[y] || y == n) {
        d[x] = n - y;
        funca(x + 1, y);
    } else {
        funca(x, y + 1);
    }
}
ll funcb(ll x, ll y){
    if (x == n) {
        return 0;
    } else if (a[y] >= b[x] || y == n) {
        return d[x] * y + funcb(x + 1, y);
    } else {
        return funcb(x, y + 1);
    }
}

int main(void){
    // Your code here!
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    for (ll i = 0; i < n; i++) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    funca(0, 0);
    cout << funcb(0, 0) << endl;
}
