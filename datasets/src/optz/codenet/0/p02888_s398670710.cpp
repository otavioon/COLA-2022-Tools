#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

vector<u64> L(1001, 0);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int l;
    int lmax = 0;
    rep (i, N)
    {
        cin >> l;
        ++L[l];
        lmax = MAX(lmax, l);
    }

    u64 ans = 0;
    for (int i = 1; i <= lmax; ++i)
    {
        if  (L[i]  == 0) continue;
        for (int a = 1; a <= i; ++a)
        {
            for (int b = a; b <= i; ++b)
            {
                if (L[a] == 0 || L[b] == 0 || a + b <= i) continue;
                if (a == i && b != i) ans += L[i] * MAX(L[a] - 1, 0) * L[b] / 2;
                else if (b == i && a != i) ans += L[i] * L[a] * MAX(L[b] - 1, 0) / 2;
                else if (a == b && a != i) ans += L[i] * L[a] * MAX(L[b] - 1, 0) / 2;
                else if (a == b && a == i) ans += L[i] * MAX(L[a] - 1, 0) * MAX(L[b] - 2, 0) / 6;
                else ans += L[i] * L[a] * L[b];
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

