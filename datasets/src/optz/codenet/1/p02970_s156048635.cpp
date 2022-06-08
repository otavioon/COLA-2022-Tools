#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MAXN 100001

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {

    int n, d, ans;
    cin >> n >> d;
    for(int i=1; i<21; i++) {
        if (n < (i*2+1)*d) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

}

