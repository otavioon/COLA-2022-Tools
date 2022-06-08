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
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

vs32 canuse;

int solve(int n)
{
    int ret = 0;
    if (n >= 10)
    {
        ret = solve(n / 10);
    }

    if (ret > n / 10)
    {
        ret = ret * 10 + canuse[0]; // add smallest number
    }
    else
    {
        int i = 0;
        while (i < canuse.size() && canuse[i] < n % 10)
        {
            ++i;
        }

        if (i < canuse.size())
        {
            ret = ret * 10 + canuse[i];
        }
        else
        {
            ret = ((canuse[0] != 0) ? canuse[0] : canuse[1]) * 10 + canuse[0];
        }
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<bool> d(10, true);
    int D;
    rep (i, K)
    {
        cin >> D;
        d[D] = false;
    }

    rep (i, d.size())
    {
        if (d[i])
        {
            canuse.push_back(i);
        }
    }

    cout << solve(N) << "\n";
    return 0;
}

