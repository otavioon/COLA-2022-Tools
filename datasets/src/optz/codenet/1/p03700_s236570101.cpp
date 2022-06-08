#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

llong n, a, b;
llong h[100005];

bool check(llong k) {
    llong t = k;
    for (int i = 0; i < n; i++) {
        llong valid = k;
        llong invalid = -1;

        while (valid - invalid > 1) {
            llong mid = (valid + invalid) / 2;
            
            if (mid * a + (t - mid) * b >= h[i]) {
                valid = mid;
            }
            else {
                invalid = mid;
            }
        }

        if (valid * a + (t - valid) * b < h[i]) return false;

        k -= valid;
    }

    return true;
}

int main() {

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    llong valid = 1ll << 33ll;
    llong invalid = -1;
    while (valid - invalid > 1) {
        llong mid = (valid + invalid) / 2;
        if (check(mid)) {
            valid = mid;
        }
        else {
            invalid = mid;
        }
    }

    cout << valid << endl;

    return 0;
}
