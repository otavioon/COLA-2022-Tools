#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;

int main() {
    int sum = 0, tr = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            int c;
            cin >> c;
            if(i == j)
                tr += c;
            sum += c;
        }
    }
    cout << (sum == 3 * tr ? "Yes" : "No") << endl;
}
