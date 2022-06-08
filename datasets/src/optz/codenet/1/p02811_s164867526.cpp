#pragma GCC optimize(2)

#include "bits/stdc++.h"

using namespace std;

//#define _DEBUG
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

const int N = 1005;
int mem[N][N];
vector<vector<int>> road;
int r;

int dfs(int row, int col) {
    if (mem[row][col] != -1) {
        return mem[row][col];
    }
    if (row == r) {
        return 0;
    }
    int res = max(dfs(row + 1, col), dfs(row + 1, col + 1)) + road[row][col];
    mem[row][col] = res;
    return res;
}

void solve() {
    int k, x;
    cin >> k >>x ;
    if (k*500 >= 500) {
        cout <<"Yes";
    } else {
        cout << "No";
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    // 加速输入和输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

