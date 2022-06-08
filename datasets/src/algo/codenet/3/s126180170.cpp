#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
#define pb push_back
using pii = pair<int, pair<int,int>>;
#define fi first
#define se second
const int N = 1e5 + 10;
long long bar[N];
int n;
int a[N], b[N], c[N];
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++) scanf("%d", b + i);
        for (int i = 0; i < n; i++) scanf("%d", c + i);

        sort(a, a + n);
        sort(b, b + n);
        sort(c, c + n);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && c[j] <= b[i]) j++;
            bar[i] = n - j;
        }
        for (int i = n - 2; i >= 0; i--) {
            bar[i] += bar[i + 1];
        }
        long long res = 0;
        j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && b[j] <= a[i]) j++;
            res += bar[j];
        }
        cout << res << endl;
    }

    return 0;
}
