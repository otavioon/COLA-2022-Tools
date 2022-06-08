#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1061109567;
const ll LINF = 4557430888798830399ll;

/* --- */

void TestCase() {
    ll n;
    scanf("%lld", &n);
    if(n & 1) {
        printf("%lld\n", n * 2);
        return;
    }
    printf("%lld\n", n);
}

int main() {
#ifdef KisekiPurin
    freopen("KisekiPurin.in", "r", stdin);
    //freopen("KisekiPurin.out", "w", stdout);
#endif // KisekiPurin
    //InitCase();
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        //printf("Case #%d: ", i);
        TestCase();
    }
    return 0;
}
