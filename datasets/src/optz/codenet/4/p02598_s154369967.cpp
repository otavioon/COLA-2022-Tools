#pragma GCC optimize(2)

#include "bits/stdc++.h"

using namespace std;

#define all(a) begin(a), end(a)
#define MOD 1000000007
#define PII pair<int, int>
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
typedef vector<int> VI;
typedef long long ll;

ll quick_pow(ll a, ll b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = a * res;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    a = abs(a), b = abs(b);
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool is_prime(int n) {
    if (n == 0) return false;
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int j = sqrt(n);
    for (int i = 2; i <= j; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

ll reverse_num(ll n) {
    ll x = 0, t = n;
    while (t != 0) {
        x = x * 10 + t % 10;
        t /= 10;
    }
    return x;
}

vector<ll> arr;
ll n, k;

bool check(ll len) {
    ll times = 0;
    for (int i = 0; i < n; ++i) {
        times += arr[i] / len;
        if (arr[i] % len == 0) times--; // 刚好够，不需要切
    }
    return times <= k;
}

void solve() {
    //    freopen("C:\\Users\\26019\\Downloads\\P1195_4.in", "r", stdin);
    //    fclose(stdin);
    ll left = 0, right = 0;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr.at(i);
        right = max(right, arr.at(i));
    }
    while (left < right) {
        ll m = (left + right) / 2;
        if (check(m)) right = m;
        else left = m + 1;
    }
    cout << left;
}

int main() {
    // 加速输入和输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

