#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF INT32_MAX / 2
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
#define int long long

template <class T>
vector<pair<T,T>> divisor(T n) {
    vector<pair<T,T>> r;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            r.push_back(make_pair(i, n / i));
        }
    }
    sort(r.begin(), r.end());
    return r;
}

int getdigit(int n) {
    int res = 0;
    while (n) {
        n /= 10;
        res++;
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int res = INF;
    auto v = divisor(n);
    for (int i = 0; i < v.size(); i++) {
        chmin(res,max(getdigit(v[i].first), getdigit(v[i].second)));
    }
    cout << res << endl;
    return 0;
}