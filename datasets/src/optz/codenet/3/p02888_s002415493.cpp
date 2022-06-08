#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int i,j;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    ll sum = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int tmp=a[i] + a[j];
            int k=lower_bound(a.begin(), a.end(), tmp) - a.begin();
            sum += (k - (j + 1));
        }
    }
    printf("%lld", sum);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
