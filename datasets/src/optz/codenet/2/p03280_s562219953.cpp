#include <iostream>
#include <fstream>
#include <iomanip>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>
#include <random>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define sz(a) static_cast<int>((a).size())
#define endl '\n'

using ll = long long;

const ll INF = static_cast<ll>(1e9) + 7;
const int MAXN = static_cast<int>(1e6) + 17;

int n, m;

bool read() {
    if (!(cin >> n >> m))
        return false;

    return true;
}

void solve() {
    cout << n * m - (n + m - 1) << endl;
}

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::mt19937 rand('S' + 'E' + 'R' + 'E' + 'Z' + 'H' + 'K' + 'A');

    while (read())
        solve();

    return 0;
}

