/*
[agc029] B - Powers of two
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 2e5;

int N;
int A[MAX_N];

ll bits_msb(ll v) {
    for (unsigned int i = 1; i < sizeof(v) * 8; i <<= 1) {
        v = v | (v >> i);
    }
    return v ^ (v >> 1);
}

ll solve() {
    multiset<ll> s;
    for (int i = 0; i < N; i++) {
        s.insert(A[i]);
    }

    ll ans = 0;
    while (!s.empty()) {
        ll a = *s.rbegin();
        s.erase(--s.end());
        auto iter = s.find((bits_msb(a) << 1) - a);
        if (iter != s.end()) {
            ans++;
            s.erase(iter);
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
