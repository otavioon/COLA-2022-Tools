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

    string n; int k;
    cin >> n >> k;

    set <int> s;
    for (int i = 0; i < 10; i++)
        s.insert(i);
    
    for (int i = 0, x; i < k; i++)
        cin >> x, s.erase(x);
    
    for (auto c : n)
        cout << *s.lower_bound(c - '0');
    cout << '\n';
    return 0;
}
