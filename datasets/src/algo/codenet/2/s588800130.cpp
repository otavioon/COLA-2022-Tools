#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back

const int N = 2e5 + 10;

int n;
int a[N];
multiset<int> st;

signed main()
{
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        st.insert(x);
    }
    int ans = 0;
    while(st.size() > 0)    {
        auto it = st.end(); it --;
        int cur = (*it); st.erase(it);
        FOR(i, 0, 30) if((1 << i) >= cur) {
            int rem = (1 << i) - cur;
            it = st.find(rem);
            if(it != st.end()) {
                ans ++; st.erase(it);
            }
        }
    }
    printf("%d", ans);
}
