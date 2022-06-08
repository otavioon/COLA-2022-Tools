#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

multiset<ll> st;


int main() {
    int n;
    scanf("%d", &n);
    ll a;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        st.insert(a);
    }

    int ans = 0;
    while (st.size() > 1) {
        ll x = *(--st.end());
        st.erase(--st.end());

        int ok;
        for (int i = 30; i >= 0; --i){
            if (x >= (1<<i)){
                ok = i + 1;
                break;
            }
        }

        ll b = (1<<ok) - x;

        if (st.find(b) != st.end()){
            auto it = st.find(b);
            st.erase(it);
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}
