#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n, d;
    cin >> n >> d;
    int ans = 0;
    for (int i = d; i < n; i += 2 * d + 1)
    {
        ans++;
        if (i + d < n - 1 && i + 2 * d + 1 >= n)
        {
            ans++;
            break;
        }
    }
    cout << ans << endl;
}