#include<bits/stdc++.h>
using namespace std;

const int MN = 200010;

int N;
multiset<int> st;
int chk[MN];

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int t; scanf("%d", &t);
        st.insert(t);
    }

    int ans = 0;
    while(st.size() > 1) {
        int t = *st.rbegin(); st.erase(st.find(t));

        int p = 1;
        while(p <= t) p <<= 1;
        int d = *st.lower_bound(p - t);
        if(d == p - t) {
            ans++;
            st.erase(st.find(d));
        }
    }
    printf("%d", ans);
}
