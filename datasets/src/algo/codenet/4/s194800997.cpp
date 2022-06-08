#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pll;

#define pb push_back
#define mp make_pair
#define all(_c) _c.begin(), _c.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; int k;
    cin >> n >> k;

    set <int> s;
    for (int i = 0; i < 10; i++)
        s.insert(i);
    
    for (int i = 0, x; i < k; i++)
        cin >> x, s.erase(x);
    
    for (int i = n; i <= 1e5; i++) {
        bool f = 1;
        for (int t = i, p = 1; t && f; t /= 10, p *= 10)
            if (s.find(t % 10) == s.end())
                f = 0;
        if (f) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
