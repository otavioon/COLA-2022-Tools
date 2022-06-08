#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


int main() {

    ll n;
    cin >> n;
    for (ll i = 2; i <= 1000000000; i = i + 2) {
        if (i % n == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}