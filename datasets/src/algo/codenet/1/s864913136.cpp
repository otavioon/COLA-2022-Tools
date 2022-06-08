#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <climits>
#include <unordered_map>
#include <functional>


#define rep(i, n) for(int i = 0, end = (int)(n); i < end; i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

inline int ctoi(char c) {
    return (int)(c -'0');
}

// ----------------------------------------------------------

int main() {
    ll yoko[3] = {0,0,0};
    ll tate[3] = {0,0,0};
    rep(i, 3) {
        ll a, b, c;
        cin >> a >> b >> c;
        yoko[i] = a + b + c;
        tate[0] += a;
        tate[1] += b;
        tate[2] += c;
    }

    bool flag_y = yoko[0] % 3 == yoko[1] % 3 && yoko[0] % 3 == yoko[2] % 3;
    bool flag_t = tate[0] % 3 == tate[1] % 3 && tate[0] % 3 == tate[2] % 3;
    bool flag = flag_y | flag_t;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
