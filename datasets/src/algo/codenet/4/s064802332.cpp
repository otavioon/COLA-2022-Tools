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
    
    int num = 0;
    for (int t = n, p = 1; t; t /= 10, p *= 10) {
        int dig = *s.lower_bound(t % 10);
        num += p*dig;
    }

    cout << num;
    if (num < n) cout << *s.lower_bound(0);
    cout << '\n'; 
    return 0;
}
