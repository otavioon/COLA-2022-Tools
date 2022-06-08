#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    multiset<int> st;

    rep(i, n) {
        int a;
        cin >> a;
        st.insert(a);
    }

    int ans = 0;
    while(st.size()) {

        auto it = st.end();
        it--;

        int a = *it;

        st.erase(it);

        int b = 1;
        while(b <= a) {
            b *= 2;
        }

        b -= a;

        auto jt = st.find(b);

        if(jt != st.end()) {
            ans++;
            st.erase(jt);
        }
    }

    cout << ans << endl;
    return 0;
}