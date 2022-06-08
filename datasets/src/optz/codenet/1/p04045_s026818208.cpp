#include <iostream>

int n, k;
bool D[10];

bool check( int n ) {
    while (n > 0) {
        if ( D[ n%10 ] ) return false;
        n /= 10;
    }
    return true;
}

void solve() {
    int ans = n;
    bool flag = true;
    while ( flag ) {
        if ( check( ans ) ) {
            std::cout << ans << std::endl;
            flag = false;
        } else {
            ++ans;
        }
    }
}

int main() {
    std::cin >> n >> k;
    for (int i=0; i<k; ++i) {
        int idx;
        std::cin >> idx;
        D[idx] = true;
    }
    solve();
    return 0;
}